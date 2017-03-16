#!/usr/bin/python3

from collections import Counter


f_in = open('c.in')
f_out = open('c.out', 'w')

lines = (i for i in f_in.read().splitlines())
t = int(next(lines))

for case in range(1, t+1):
    n = int(next(lines))
    topics = []
    for i in range(n):
        topics.append(next(lines).lower().split())

    lefts, rights = zip(*topics)
    lefts = Counter(lefts)
    rights = Counter(rights)
    chosen = []
    fake = []
    unknown = []

    for l, r in topics:
        if lefts[l] == 1 or rights[r] == 1:
            chosen.append((l, r))
        else:
            unknown.append((l, r))

    while unknown:
        print(chosen)
        print(fake)
        print()
        lefts, rights = zip(*chosen) if chosen else ([], [])
        lefts = Counter(lefts)
        rights = Counter(rights)
        old_unknown = unknown
        unknown = []
        for l, r in old_unknown:
            if lefts[l] >= 1 and rights[r] >= 1:
                fake.append((l, r))
            else:
                unknown.append((l, r))

        if len(unknown) == len(old_unknown):
            for i, (l, r) in enumerate(old_unknown):
                if lefts[l] == 0 and rights[r] == 0:
                    chosen.append(unknown.pop(i))
                    break
            else:
                print(case)
                for i, (l, r) in enumerate(old_unknown):
                    if lefts[l] == 0 or rights[r] == 0:
                        chosen.append(unknown.pop(i))
                        break

                else:
                    chosen.append(unknown.pop(0))

    lefts, rights = zip(*chosen) if chosen else ([], [])
    lefts = Counter(lefts)
    rights = Counter(rights)
    extra = 0

    for l, r in chosen:
        if lefts[l] > 1 and rights[r] > 1:
            extra += 1

    f_out.write('Case #{}: {}\n'.format(case, len(fake) + extra))
