def f(test):
    s, n = raw_input().split()
    n = int(n)
    res = 0
    vowels = 'aeiou'
    l = []
    loc = 0
    if s[0] not in vowels:
        loc = 1
        if loc == n:
            l.append(0)
    for i in xrange(1, len(s)):
        if s[i] not in vowels:
            loc += 1
            if i >= n and loc == n + 1:
                if s[i - n] not in vowels:
                    loc -= 1
            if loc == n:
                l.append(i)
        else:
            loc = 0
    
    slen = len(s)
    if len(l):
        res += (l[0] - n + 1 + 1) * (slen - l[0])
        for i in xrange(1, len(l)):
            res += (l[i] - l[i - 1]) * (slen - l[i])
    
    print "Case #" + str(test) + ': ' + str(res)


t = int(input())
for _ in xrange(t):
    f(_ + 1)
