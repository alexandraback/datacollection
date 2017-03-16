def solve():
    A, B = map(int, raw_input().split())
    N = len(str(A))
    answer = set()
    for n in xrange(A, B):
        string = str(n)
        for i in xrange(1, N):
            m = int(string[i:] + string[:i])
            if n < m <= B:
                answer.add((n, m))
    return len(answer)

T = int(raw_input())
for i in range(T):
    print "Case #%d:" % (i + 1), solve()
