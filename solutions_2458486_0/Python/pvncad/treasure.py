#/usr/local/bin/python

import sys

from collections import deque


class State(object):

    def __init__(self, keys, chests, used_path=[]):
        self.keys = keys
        self.chests = chests
        self.used_path = used_path

    def __str__(self):
        desc = "Keys: %s; Chests: %s" % (self.keys, self.chests)

        if len(self.used_path) > 0:
            desc = "%s; Used: %s" % (desc, self.used_path)

        return desc

    def __hash__(self):
        return hash(frozenset(self.keys.keys())) ^ hash(frozenset(self.chests.keys()))

    def __eq__(self, other):
        return self.keys == other.keys and self.chests == other.chests

    def open_chest(self, chest):
        key, extra_keys = self.chests[chest]

        new_keys = self.keys.copy()
        new_keys[key] -= 1

        for k in extra_keys:
            new_keys[k] = new_keys.get(k, 0) + 1

        if new_keys[key] == 0:
            del new_keys[key]

        new_chests = self.chests.copy()

        del new_chests[chest]

        new_used_path = self.used_path[:]
        new_used_path.append(str(chest + 1))
        return State(new_keys, new_chests, new_used_path)

    def is_complete(self):
        return len(self.chests) == 0


T = int(sys.stdin.readline())

for caseno in xrange(T):
    K, N = [int(x) for x in sys.stdin.readline().split()]

    init_keys = dict()
    for x in sys.stdin.readline().split():
        x = int(x)
        init_keys[x] = init_keys.get(x, 0) + 1

    init_chests = dict()

    for i in xrange(N):
        values = [int(x) for x in sys.stdin.readline().split()]
        init_chests[i] = (values[0], values[2:])

    init_state = State(init_keys, init_chests)

    S = [init_state]
    visited = set()
    visited.add(init_state)

    found = None
    while len(S) > 0:
        t = S.pop()

        if t.is_complete():
            found = t
            break;

        for chest in sorted(t.chests.keys(), reverse=True):
            key, rest = t.chests[chest]
            if key in t.keys:
                newT = t.open_chest(chest)
                if newT not in visited:
                    visited.add(newT)
                    S.append(newT)

    res  = ""

    if found is None:
        res = "IMPOSSIBLE"
    else:
        res = " ".join(found.used_path)

    print "Case #%d: %s" % (caseno + 1, res)
