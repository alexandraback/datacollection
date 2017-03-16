

case = 0
T = input()

def res(a, b):
    a = a.split()
    b = b.split()
    alen = len(a)
    blen = len(b)
    for i in range(alen):
        a[i] = int(a[i])
    for i in range(blen):
        b[i] = int(b[i])
    a.sort()
    b.sort()
    c = a + b
    a.remove(0)
    b.remove(0)
    
    for elem in c:
        if elem in a and elem in b:
            a.remove(elem)
            b.remove(elem)
    alen = len(a)
    blen = len(b)
    ans = str(a[0])
    for i in range(1,alen):
        ans += ' '+str(a[i])
    print ans
    ans = str(b[0])
    for i in range(1,blen):
        ans += ' '+str(b[i])
    print ans
    

for t in range(T):
    case += 1
    cin = raw_input().split()
    print 'Case #'+str(case)+':'
    n = int(cin[0])
    arr = [0] * n
    for i in range(1,n+1):
        arr[i-1] = int(cin[i])
    arr.sort()
    val = [0]
    maps = {'0':'0'}
    #for i in val:
    #    maps[str(i)] = str(i)
    brk = False
    for i in range(0,n):
        m = len(val)
        for j in range(0,m):
            k = val[j]+arr[i]
            #print maps
            if str(k) in maps:
                res(maps[str(k)], maps[str(val[j])]+' '+str(arr[i]))
                brk = True
                break
            else:
                maps[str(k)] = maps[str(val[j])]+' '+str(arr[i])
                val.append(k)
        if brk: break
    if not brk:
        print 'Impossible'
    
