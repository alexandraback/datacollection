
import sys
import math

def solve(line):
    r,c,w = [int(i) for i in line.split(' ')]
    return (r-1)*int(math.ceil(c/w)) + int(math.ceil((c-w)/w)) + w

def main():
    t = int(sys.stdin.readline())
    for i in range(t):
        s = solve(sys.stdin.readline())
        print("Case #{0}: {1}".format(i+1, s))

if __name__ == '__main__':
    main()
