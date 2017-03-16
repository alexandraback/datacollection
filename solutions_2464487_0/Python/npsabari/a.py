def fun(x, r):
    return (2*x + (2*r - 1))*x

def binsearch(a, b):
    l = 0
    r = b/a+1
    m = 0
    while l < r:
        m = (l+r)/2
        t = fun(m, a)
        if t == b:
            return m
        elif t < b:
            l = m+1
        else:
            r = m-1
    t = fun(l, a)
    if t > b:
        return l-1
    else:
        return l

def main():
    a = int(raw_input())
    k = 1
    while k <= a:
        stri = raw_input().strip().split()
        print 'Case #'+str(k)+': '+ str(binsearch(long(stri[0]), long(stri[1])))
        k += 1

if  __name__ =='__main__':
    main()    
