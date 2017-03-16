def go(c, j, i, eq):
    # assuming c bigger or equal than j
    if c[:i] < j[:i]:
        return 0
    if i == len(c):
        return ''.join(c), ''.join(j)

    if c[i] == '?' and j[i] == '?':
        a = c[:]
        b = j[:]
        a[i] = '0'
        b[i] = '9'
        r = go(a, b, i+1, False)
        if r:
            return r
        a[i] = '0'
        b[i] = '0'
        r = go(a, b, i+1, eq)
        if r:
            return r
        a[i] = '1'
        b[i] = '0'
        return go(a, b, i+1, False)
            
    
    if c[i] != '?' and j[i] == '?':
        b = j[:]
        
        if not eq:
            b[i] = '9'
            r = go(c, b, i+1, eq)
            if r:
                return r
        
        b[i] = c[i]
        r = go(c, b, i+1, eq)
        if r:
            return r
        if c[i] == '0':
            return 0
        b[i] = str(int(c[i])-1)
        return go(c, b, i+1, False)
        
    if c[i] == '?' and j[i] != '?':
        a = c[:]
        
        if not eq:
            a[i] = '0'
            r = go(a, j, i+1, eq)
            if r:
                return r
    
        a[i] = j[i]
        r = go(a, j, i+1, eq)
        if r:
            return r
        if j[i] == '9':
            return 0
        a[i] = str(int(j[i])+1)
        return go(a, j, i+1, False)
        
    if c[i] != '?' and j[i] != '?':
        return go(c, j, i+1, eq and c[i]==j[i])


for t in range(1, int(input())+1):
    c, j = map(list, raw_input().split())
    a = go(c, j, 0, True)
    b = go(j, c, 0, True)
    if a and b:
        diff1 = int(a[0])-int(a[1])
        diff2 = int(b[0])-int(b[1])
        if diff1 < diff2:
            ans = a
        elif diff1 > diff2:
            ans = b[::-1]
        else:
            if ''.join(a) < ''.join(b):
                ans = a
            else:
                ans = b[::-1]
    else:
        if a:
            ans = a
        if b:
            ans = b[::-1]
            
    print "Case #%d: " % t + "%s %s" % ans