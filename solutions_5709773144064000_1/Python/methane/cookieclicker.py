import sys


def solve(C, F, X):
    rate = 2.0
    tt = 0.0

    while True:
        t1 = X / rate
        t2 = C / rate
        t3 = X / (rate + F)
        #print(t1, t2, t3)
        if t1 <= t2 + t3:
            return tt + t1
        tt += t2
        rate += F

#def test():
#    print(solve(30.50000,3.14159, 100000.0))

def main():
    T = int(sys.stdin.readline())

    for t in range(1, T+1):
        c, f, x = map(float, sys.stdin.readline().split())
        y = solve(c, f, x)
        print("Case #{}: {}".format(t, y))

#test()
main()
