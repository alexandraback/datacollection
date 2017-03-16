import sys
stdin = sys.stdin

sys.setrecursionlimit(3000)

def rl(s):
    return xrange(len(s))

def tobits(N):
    if 0 == N:
        return [0]
    return tobits(N/2) + [N%2]

def pad(seq, tolen):
    return [0] * (tolen - len(seq)) + seq

def whatNumber(s):
    re = 0
    for i, bit in enumerate(reversed(s)):
        re += (bit << i)
    return re

def countThem(kp, ap, bp, otherbits, atail, btail):
    """The number of ways they can make this exact prefix kp."""
    re = 0
    for ia in range(len(ap)+1):
        if ia < len(ap) and 0 == ap[ia]:
            continue
        for ib in range(len(bp)+1):
            if ib < len(bp) and 0 == bp[ib]:
                continue

            here = 1
            fail = False
            for i in rl(kp):
                abit = None
                bbit = None
                if i <= ia:
                    abit = ap[i]
                    if i == ia:
                        abit = 0
                if i <= ib:
                    bbit = bp[i]
                    if i == ib:
                        bbit = 0
                if 1 == kp[i]:
                    if (0 == abit or 0 == bbit):
                        fail = True
                        break
                    #Only one way to get 1.
                else:
                    if (1 == abit and 1 == bbit):
                        fail = True
                        break
                    if 1 == abit:
                        pass
                    elif 1 == bbit:
                        pass
                    elif 0 == abit and 0 == bbit:
                        pass
                    elif 0 == abit and None == bbit:
                        here *= 2
                    elif 0 == bbit and None == abit:
                        here *= 2
                    else:
                        here *= 3
            if ia == len(ap):
                here *= atail
            else:
                here *= (1 << otherbits)
            if ib == len(bp):
                here *= btail
            else:
                here *= (1 << otherbits)

                
            if fail:
                continue

            re += here
    return re


INF = 2147483647
T = int(stdin.readline())
for icase in range(T):
    A, B, K = map(int, stdin.readline().strip().split())
    a, b, k = map(tobits, [A, B, K])
    maxlen = max(map(len, [a, b, k]))
    a, b, k = map(lambda seq: pad(seq, maxlen), [a, b, k])

    re = 0
    for i in rl(k):
        if 0 == k[i]:
            continue
        re += countThem(k[:i] + [0], a[:i+1], b[:i+1], len(k)-(i+1), 
                        whatNumber(a[i+1:]), 
                        whatNumber(b[i+1:]))

    print "Case #%d:" % (icase+1), re
