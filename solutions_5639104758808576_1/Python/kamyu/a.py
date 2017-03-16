def solve():
    num, level = raw_input().split()
    num = int(num)
    ans = 0
    cur = int(level[0])
    for i in xrange(1, num + 1):
        while cur < i:
            ans += 1
            cur += 1
        cur += int(level[i])
    return ans

T = input()
for i in xrange(T):
    print 'Case #%d: %s' % (i + 1, solve())
