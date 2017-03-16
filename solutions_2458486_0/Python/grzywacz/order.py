#!/usr/bin/env python

import cProfile
import array
from copy import copy
from collections import defaultdict, namedtuple
import sys

Chest = namedtuple("Chest", "key keys")

input_file = open(sys.argv[1])
test_cases = int(input_file.next())

CACHE = set()

def solve(keys, chests):
    path = solve_internal(keys, chests, [])
    if not path:
        return "IMPOSSIBLE"
    else:
        return " ".join([str(i + 1) for i in path])

def solve_internal(keys, chests, path):
    if all(c == -1 for c in chests):
        return path

    k_sig = tuple(keys)
    c_sig = tuple((c.key if c != -1 else -1) for c in chests)

    if (k_sig, c_sig) in CACHE:
        return

    # sanity check
    available_keys = copy(keys)
    for chest in [c for c in chests if c != -1]:
        for i, v in enumerate(chest.keys):
            available_keys[i] += v
        available_keys[chest.key] -= 1

    for k in available_keys:
        if k < 0:
            CACHE.add((k_sig, c_sig))
            return None

    for chest_idx, chest in enumerate(chests):
        if chest == -1:
            continue

        if keys[chest.key] > 0:
            new_keys = copy(keys)
            new_keys[chest.key] -= 1
            backup = chests[chest_idx]
            chests[chest_idx] = -1
            for idx, chest_key in enumerate(chest.keys):
                new_keys[idx] += chest_key
            new_path = path + [chest_idx]
            possible = solve_internal(new_keys, chests, new_path)
            chests[chest_idx] = backup
            if possible:
                return possible
            else:
                CACHE.add((k_sig, c_sig))


for case_no in xrange(test_cases):
    K, N = [int(c) for c in input_file.next().strip().split(' ')]
    keys_list = [int(c) for c in input_file.next().strip().split(' ')]
    assert len(keys_list) == K
    keys = array.array("b", [0] * 41)
    for k in keys_list:
        keys[k] += 1

    chests = []
    for n in xrange(N):
        chest = [int(c) for c in input_file.next().strip().split(' ')]
        Ti = chest.pop(0)
        Ki = chest.pop(0)
        chest_keys = array.array("b", [0] * 41)
        for k in chest:
            chest_keys[k] += 1
        chests.append(Chest(Ti, chest_keys))

    answer = solve(keys, chests)
    print "Case #%d: %s" % (case_no + 1, answer)
    CACHE.clear()
