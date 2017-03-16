import sys
import math
import os


def nex(t=int):
    return t(sys.stdin.readline().strip())


m = None

def solve1(maxi):
    acum = 0
    best = int(1e10)
    for idx in range(maxi, -1, -1):

        s = int(math.ceil(math.sqrt(idx) - 0.001))
        if s*(s-1) < idx:
            toadd = 2*s - 1
        else:
            toadd = 2*s - 2

        best = min(best, idx + acum)

        acum += toadd * m[idx]

    return best

def solve2(maxi):
    global m

    if maxi <= 0:
        return 0

    if maxi == 1:
        return 1

    best = int(1e10)

    acumt = 0

    for idx in range(maxi, -1, -1):
        if not m[idx]:
            continue

        if acumt + idx < best:
            best = acumt + idx
        # print 'idx=%s, best=%s, m=%s' % (idx, best, m[:idx+1])
        m[idx / 2] += m[idx]
        m[(idx + 1) / 2] += m[idx]
        acumt += m[idx]

    return best

def solve3(maxi):
    global m

    best = 1e10
    for i in range(maxi, 0, -1):
        # Try reduce all to idx
        # print m[:i+1]
        acum = 0
        for idx in range(i+1, maxi + 1):
            if m[idx]:
                acum += m[idx] * ((idx + i - 1) / i - 1)

        if acum + i < best:
            best = acum + i

        # print 'i=%s, acum=%s, best=%s' % (i, acum, best)

    return best




def main():
    global m
    t = nex()
    for case in range(1, t + 1):
        ans = 0
        d = nex()
        l = sys.stdin.readline().split()
        m = [0] * (1005)
        maxi = 0
        for i in l:
            i = int(i)
            m[i] += 1
            maxi = max(maxi, i)

        cm = list(m)
        s1 = solve1(maxi)
        m = list(cm)
        s2 = solve2(maxi)
        m = list(cm)
        s3 = solve3(maxi)
        ans = min(s1, s2, s3)

        sys.stdout.write('Case #%s: %s\n' % (case, s3))
        # sys.stderr.write('%s, %s, %s\n' % (s1, s2, s3))


if __name__ == '__main__':
    main()
