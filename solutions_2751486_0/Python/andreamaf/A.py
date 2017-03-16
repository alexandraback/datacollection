try:
    import psyco
    psyco.full()
except ImportError: pass    


if __name__ == '__main__':

    fi = open('A.in', 'r')
    fo = open('A.out', 'w')
    T = int(fi.readline().strip('\n\r '))
    
    for t in xrange(1, T+1):
        S, n = fi.readline().strip('\n\r ').split()
        n = int(n)

        L = len(S)
        Z = [1 * (c not in ('a', 'e', 'i', 'o', 'u')) for c in S]
        
        ans = 0
        for i in xrange(L-n+1):
            for j in xrange(i, L):
                ma = 0
                for z in xrange(i, j+1):
                    if Z[z] == 0:
                        ma = 0
                        continue    
                    else:
                        ma += 1
                        if ma >= n:
                            ans += 1  
                            break
    
        fo.write('Case #%d: %d\n' % (t, ans))
