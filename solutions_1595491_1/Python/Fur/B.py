fin = open('B.in', 'r')
fout = open('B.out', 'w')
T = int(fin.readline())
for case in xrange(1, T + 1):
    L = map(int, fin.readline().strip().split())
    n, s, p = L[:3]
    del L[:3]
    for x in L:
        postoji = False
        surprise = True
        
        for a in xrange(-2, 3):
            for b in xrange(-2, 3):
                for c in xrange(-2, 3):
                    
                    y = (x / 3 + a, x / 3 + b, x / 3 + c)

                    def bound(L):
                        for x in L:
                            if x not in xrange(0, 11):
                                return False
                        return True
                    
                    if bound(y) and sum(y) == x and max(y) >= p and max(y) - min(y) <= 2:
                        postoji = True
                        if max(y) - min(y) < 2:
                            surprise = False
                            
        if not postoji:
            n -= 1
        elif surprise:
            if s > 0:
                s -= 1
            else:
                n -= 1
    fout.write('Case #' + str(case) + ': ' + str(n) + '\n')
