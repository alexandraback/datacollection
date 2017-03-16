import sys

def d(*args):
    sys.stderr.write(', '.join(map(str, args)) + "\n")

def printf(*args):
    print(''.join(map(str, args)))

def int_input():
    return list(map(int, input().split(' ')))

def solve(n, D, H, M):
    hikers = []
    for i in range(n):
        for j in range(H[i]):
            hikers.append((D[i], 360/M[i]+j)) #pos, vel
    if len(hikers) < 2:
        return 0
    if len(hikers) == 2:
        if hikers[0][1] == hikers[1][1]:
            return 0
        if hikers[0][1] < hikers[1][1]:
            s = 0
        else:
            s = 1
        tsf = (360-hikers[s][0])/hikers[s][1]
        dp = hikers[0][0] - hikers[1][0]
        dv = hikers[1][1] - hikers[0][1]
        themod = abs(360/dv)
        t = (dp/dv)%themod
        if hikers[s][0] >= hikers[1-s][0]:
            t += themod
        if tsf < t:
            return 0
        else:
            return 1
    return "Dunno :-("

def read_input():
    n = int(input())
    D = []
    H = []
    M = []
    for i in range(n):
        (d, h, m) = tuple(int_input())
        D.append(d)
        H.append(h)
        M.append(m)
    return n, D, H, M


if __name__ == '__main__':
    for i in range(int(input())):
        printf("Case #", i+1, ": ", str(solve(*read_input())))
