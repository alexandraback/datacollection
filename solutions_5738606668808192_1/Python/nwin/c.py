from itertools import product
def solve():
    n, j = map(int, raw_input().split())
    div = ' '.join(str(int('1' + '0' * (n / 2 - 1) + '1', b)) for b in xrange(2, 11))
    for m in product('01', repeat=n/2-2):
        x = '1' + ''.join(m) + '1'
        print x + x, div
        j -= 1
        if j <= 0:
            break

T = int(raw_input())
for t in xrange(T):
    print "Case #%d:" % (t + 1)
    solve()

