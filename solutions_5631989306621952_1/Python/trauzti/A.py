import sys

def solve(S):
    ans = S[0]
    first = S[0]
    last = S[0]
    for c in S[1:]:
        if c < first:
            ans = ans + c
            last = c
        else:
            ans = c + ans
            first = c
    return ans


def main():
    N = int(sys.stdin.readline())
    for tc in xrange(1, 1+N):
        S = sys.stdin.readline()
        S = S.strip()
        ans = solve(S)

        print "Case #%d: %s" % (tc, ans)

if __name__ == "__main__":
    main()
