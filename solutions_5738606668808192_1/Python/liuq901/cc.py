raw_input()
n, m = map(int, raw_input().split())
print 'Case #1:'
haha = open('haha', 'r')
haha.readline()
for i in xrange(m):
    num = haha.readline().split()
    factor = num[1:]
    num = num[0] + num[0]
    for j in xrange(2, 11):
        x = int(num, j)
        assert x % int(factor[j - 2]) == 0
    print num, ' '.join(factor)
haha.close()
