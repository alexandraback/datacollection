import sys

def solve(lines):
    d = {}
    missing = []

    for line in lines:
        for num in map(int, line.split(" ")):
            if num in d:
                d[num] += 1
            else:
                d[num] = 1
            d[num]
    for k,v in d.items():
        if (v % 2) == 1:
            missing.append(k)
    missing.sort()
    assert len(missing) == len(lines[0].split(" "))
    return " ".join(map(str, missing))

def main():
    T = int(sys.stdin.readline())
    for tc in xrange(1, 1+T):
        N = int(sys.stdin.readline())
        lines = []
        for i in xrange(2*N-1):
            line = sys.stdin.readline()
            line = line.strip()
            lines.append(line)
        ans = solve(lines)

        print "Case #%d: %s" % (tc, ans)

if __name__ == "__main__":
    main()
