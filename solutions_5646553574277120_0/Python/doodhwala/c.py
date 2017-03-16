L = []
def chk(L, v):
    for i in range(1,v+1):
        if(i in L):
            pass
        else:
            return i
    return -1

def app(L, val, v):
    L2 = [x for x in L]
    for x in L2:
        if(x + val > v):
            pass
        else:
            L.append(x+val)
    return L

for cases in range(input()):
    
    ans = 0
    c,d,v = raw_input().split()
    c,d,v = int(c),int(d),int(v)
    
    L = [int(z) for z in raw_input().split()]
    L.sort()
    
    L3 = [L[0]]
    for x in L[1:]:
        L3 = app(L3, x, v)
        L3.append(x)
        L3.sort()
    
    L = L3
    
    temp = chk(L,v)
    while(temp != -1):
        ans += 1
        L = app(L,temp, v)
        L.append(temp)
        temp = chk(L,v)
    
    print 'Case #'+str(cases+1)+':', ans
