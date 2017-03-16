vow = set(['a', 'e', 'i', 'o', 'u'])

def search(word, n, start, l):
    global q, d
    if start == l:
        return 0
    
    if start in d:
        return d[start]

    ans = 0
    if q[start] == 1:
        ans += l - start - n + 1
    else:
        ans += search(word, n, start+1, l)
    #print start, '=', ans
    d[start] = ans
    return ans

def solve(word, n):
    global q, d
    d = {}
    p = []
    l = len(word)
    for c in word:
        if c in vow:
            p.append(0)
        else:
            p.append(1)

    q = [0] * l
    i = 0
    j = 0
    cnt = 0
    while i < l and j < l:
        if p[i] == 1:
            cnt += 1
        else:
            cnt = 0

        i += 1
        if i - j == n:
            if cnt >= n:
                q[j] = 1
            j += 1

    #print 'q=', q
    
    ans = 0
    for i in xrange(l):
        ans += search(word, n, i, l)
    return ans


t = input()
for i in xrange(1, t+1):
    word, n = raw_input().split()
    n = int(n)
    ans = solve(word, n)
    print 'Case #%d: %d' % (i, ans)
