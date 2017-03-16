vis = set()

def f(n):
    global vis
    l = len( str(n) )

    arr = []
    for i in xrange(l):

        t = n % 10
        n = (n%10) * (10 ** (l-1)) + n/10

        if t:
            arr.append(n)

    arr = list( set(arr) )
    arr = filter(lambda n: a<=n<=b, arr)

    n = len(arr) - 1
    if arr[0] in vis:
        return 0
    else:
        vis |= set(arr) 
        return n * (n+1) / 2

T = input()
a, b = 0, 0
for case in xrange(T):
    a, b = map(int, raw_input().split())

    vis = set()
    ans = 0
    for i in xrange(a, b+1):
        ans += f(i)

    print 'Case #%d: %d' % (case+1, ans)

