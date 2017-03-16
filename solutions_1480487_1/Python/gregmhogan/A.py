#!/usr/bin/env python

def run_one(N, S):
    M = []
    X = sum(S)

    for i, s in enumerate(S):
        #p = s - float(2*X - s) / (N-1)
        #v = X * (1 + 1 / float(N-1))
        #M.append(abs(100 * p / v))
        #print s, X, p, v

        #m = 100*(2.0*X-N*s)/(N*X)
        #if m <= 0.0:
        #    M.append(0)
        #else:
        #    M.append(m)


        l = 0.0
        r = 100.0

        while r - l > 10**-9:
            t = (r + l) / 2
            my_score = s + X * t
            remain = 1 - t
            for j, sj in enumerate(S):
                if i != j:
                    y = (my_score - sj) / X
                    if y > 0:
                        remain -= y
            if remain >= 0:
                l = t
            else:
                r = t

        M.append(100 * (r + l) / 2)


    return M


def run(lines):
    output = []

    # Number of test cases
    T = int(lines.popleft())
    for t in range(T):
        line = [int(x) for x in lines.popleft().split()]
        N, S = line[0], line[1:]

        #print t, N, S
        M = run_one(N, S)

        output.append('Case #{0}: {1}'.format(t + 1, ' '.join(map(str, M))))

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
