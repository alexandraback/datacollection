import sys

def d(*args):
    sys.stderr.write(', '.join(map(str, args)) + "\n")

def printf(*args):
    print ''.join(map(str, args))

def int_input():
    return map(int, raw_input().split(' '))

def float_input():
    return map(float, raw_input().split(' '))

def solve(c, f, x):
    currentTime = 0
    n = 0
    while True:
        timeToX = x / (f*n + 2)
        timeToC = c / (f*n + 2)
        timeToCThenX = timeToC + x / (f*(n+1) + 2)
        if timeToX < timeToCThenX:
            return currentTime + timeToX
        else:
            currentTime += timeToC
            n += 1

def read_input():
    return tuple(float_input())

if __name__ == '__main__':
    for i in xrange(int(raw_input())):
        printf("Case #", i+1, ": ", str(solve(*read_input())))
