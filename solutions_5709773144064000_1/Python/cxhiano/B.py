import sys

def solve(C, F, X):
    if C > X:
        return X / 2.0
    t = 0
    prdt = 2.0
    while X / (prdt + F) + C / prdt < X / prdt:
        t += C / prdt
        prdt += F
    return t + X / prdt

if __name__ == '__main__':
    T = int(raw_input())
    for t in range(T):
        C, F, X = map(float, raw_input().split())
        print 'Case #{0}: {1}'.format(t + 1, solve(C, F, X))
