try:
    import psyco
    psyco.full()
except ImportError: pass    


def bfs(P):
    D = {(0, 0): ''}
    for i in xrange(1, 501 + 1):
        
        D2 = {} 
        for (x, y), s in D.iteritems():
            
            p = (x, y + i)
            if p == P:
                return s + 'N'
            elif p not in D2:
                D2[p] = s + 'N'
            
            p = (x, y - i)
            if p == P:
                return s + 'S'
            elif p not in D2:
                D2[p] = s + 'S'
            
            p = (x + i, y)
            if p == P:
                return s + 'E'
            elif p not in D2:
                D2[p] = s + 'E'
            
            p = (x - i, y)
            if p == P:
                return s + 'W'
            elif p not in D2:
                D2[p] = s + 'W'
        
        D = D2.copy()
        del D2                
            

if __name__ == '__main__':

    fi = open('B.in', 'r')
    fo = open('B.out', 'w')
    T = int(fi.readline().strip('\n\r '))
    
    for tst in range(1, T+1):
        X, Y = map(int, fi.readline().strip('\n\r ').split())
        path = bfs((X, Y))
        fo.write('Case #%d: %s\n' % (tst, path))
