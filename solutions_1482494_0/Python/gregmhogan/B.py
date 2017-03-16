#!/usr/bin/env python

from collections import defaultdict

def run_one(N, stars):
#5
#a 0 5
#b 0 1
#c 1 1
#d 4 7
#e 5 6
#
#b1 b2 c2 d1 a2 e2 d2
#a1 b2 c2 a2 e2 d2
#
#always play second if possible (earns one or two stars)
#else play the first with the largest second
    played = 0

    #seconds = defaultdict(list)
    #for level in range(N):
    #    s1, s2 = stars[level]
    #    seconds[s2].append(level)

    stars.sort(key=lambda x: (x[1], -x[2]))

    seconds = list(stars)
    seconds.sort(key=lambda x: x[2])

    played_1st = set()
    played_2nd = set()

    collected = 0
    while True:
        #print stars, seconds
        if collected == 2 * N:
            return played

        if seconds[0][2] <= collected:
            idx = seconds[0][0]
            played_2nd.add(idx)

            if idx in played_1st:
                played_1st.remove(idx)
                collected += 1
            else:
                collected += 2

            seconds = seconds[1:]
            played += 1
        elif stars[0][1] <= collected:
            idx = stars[0][0]
            if idx in played_2nd:
                stars = stars[1:]
                continue

            collected += 1
            played_1st.add(idx)

            stars = stars[1:]
            played += 1
        else:
            return None


def run(lines):
    output = []

    # Number of test cases
    T = int(lines.popleft())
    for t in range(T):
        N = int(lines.popleft())
        stars = []
        for n in range(N):
            s1, s2 = [int(x) for x in lines.popleft().split()]
            stars.append([n, s1, s2])

        try:
            played = run_one(N, stars)
        except:
            played = None

        if played is None:
            output.append('Case #{0}: Too Bad'.format(t + 1))
        else:
            output.append('Case #{0}: {1}'.format(t + 1, played))

    return output


# Google Code Jam submissions must run stand-alone.
# This code shall be copied into each solution.
if __name__ == '__main__':
    import os
    import sys
    from collections import deque

    infile = sys.argv[1]
    with open(infile) as file:
        lines = deque(file.readlines())
        output = run(lines)
        print os.linesep.join(output)
