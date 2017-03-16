import sys

def solve(r, t):
    done = 0
    needed = 0
    while True:
        needed += 2 * r + 1
        if needed > t:
            break
        done += 1
        r += 2
    return done

def main():
    T = int(sys.stdin.readline())
    for test in range(T):
        r, t = map(int, sys.stdin.readline().split())
        result = solve(r, t)
        print "Case #%d: %s" % (test + 1, result)

if __name__ == '__main__':
    main()
