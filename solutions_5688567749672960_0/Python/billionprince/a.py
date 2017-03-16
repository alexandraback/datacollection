def rev(num):
    lst = list(str(num))
    lst.reverse()
    return int(''.join(lst))

ncase = int(raw_input())
for case in range(0, ncase):
    ans, n = 0, int(raw_input())
    dic = [0 for i in range(0, n+1)]
    for i in range(1, n+1):
        dic[i] = dic[i-1] + 1
        t = rev(i)
        if len(str(t)) < len(str(i)):
            continue
        if t < i:
            dic[i] = min(dic[i], dic[t]+1)
    ans = dic[n]
    print 'Case #%d: %d' % (case+1, ans)
