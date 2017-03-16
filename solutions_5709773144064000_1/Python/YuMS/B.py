import sys
def solve():
    CFX = raw_input()
    C, F, X = map(float, CFX.split())
    total = 0.0
    speed = 2.0
    while True:
        wait = X / speed
        farm_and_wait = C / speed + X / (speed + F)
        if wait < farm_and_wait:
            total += wait
            break
        else:
            total += C / speed
            speed += F
    print '%.7f' % total

def main():
    T = input()
    for i in range(1, T + 1):
        print 'Case #%d:' % i,
        solve()

if __name__ == '__main__':
    main()
