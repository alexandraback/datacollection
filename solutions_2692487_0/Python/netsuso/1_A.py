#!/usr/bin/python3

import sys

ncases = int(sys.stdin.readline())

for t in range(1, ncases+1):
    (A, N) =  [int(x) for x in sys.stdin.readline().strip().split(" ")]
    motes = [int(x) for x in sys.stdin.readline().strip().split(" ")]
    motes.sort()

    finished = False
    additions = 0
    bestByRemoving = N
    for i in range(0, N):
        remaining = N - i
        if (additions + remaining) < bestByRemoving:
            bestByRemoving = additions + remaining
        # If the current mote is smaller than Armin's size, just absorb it
        if motes[i] < A:
            A += motes[i]
            continue
        else:
            while motes[i] >= A:
                if A == 1:
                    finished = True
                    break
                # Inserting a new mote with a size equal to current A minus 1, and count a new addition
                A += A-1
                additions += 1
                # If the number of additions is bigger than the best solution with removing, finish now
                if additions >= bestByRemoving:
                    finished = True
                    break
            if finished:
                break
            A += motes[i]

    if finished:
        print("Case #%d: %d" % (t, bestByRemoving))
    else:
        print("Case #%d: %d" % (t, additions))
