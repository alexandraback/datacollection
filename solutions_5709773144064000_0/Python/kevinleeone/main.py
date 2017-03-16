import sys

def catchUpCookies(cost, prevProduction, increment):
    return cost * (prevProduction + increment) / increment

def solve():
    production = 2.0
    time = 0.0
    cost, increment, target = map(float, sys.stdin.readline().split())
    while catchUpCookies(cost, production, increment) < target:
        time += cost / production
        production += increment
    time += target / production
    return time

if __name__ == '__main__':
    cases = int(sys.stdin.readline().split()[0])
    for i in range(cases):
        print('Case #%d: %.7f' % (i + 1, solve()))
