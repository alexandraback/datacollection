#!/usr/bin/env python

from itertools import permutations

def test(sentence):
    used = set()
    last = None
    for letter in sentence:
        if last and letter == last:
            continue
        if letter in used:
            return False
        used.add(letter)
        last = letter
    return True


def solve(N, trains):
    if any(not test(train) for train in trains):
        return 0
    trains = sorted(trains)
    cache = {}
    def _solve(N, trains, start=None):
        cachekey = '%s:%s:%s' % (N, ','.join(trains), start)
        if cachekey in cache: return cache[cachekey]
        if N == 1: return 1 if start is None or trains[0][0] == start else 0
        cnt = 0
        for index in range(N):
            train = trains[index]
            if start and train[0] != start:
                continue
            last_letter = train[-1]
            letters = set(train) - set([last_letter])
            remaining_trains = trains[:index] + trains[index+1:]
            remaining_letters = set(''.join(remaining_trains))
            if letters & remaining_letters:
                continue
            cnt += _solve(N-1, remaining_trains, last_letter if last_letter in remaining_letters else None)
        cache[cachekey] = cnt
        return cnt
    return _solve(N, trains)


T = int(raw_input().strip())
for t in range(T):
    N = int(raw_input().strip())
    trains = raw_input().strip().split()
    print 'Case #%d: %s' % (t+1, solve(N, trains))
