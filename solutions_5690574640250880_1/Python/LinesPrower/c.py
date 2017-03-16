'''
Created on Apr 12, 2014

@author: linesprower
'''
import io, sys
import datetime

def solve(fin):
    def nums():
        return [int(x) for x in fin.readline().split()]
    def fnums():
        return [float(x) for x in fin.readline().split()]
    def num():
        return int(fin.readline())
    
    def do(r, c, m):
        f = r * c - m
        res = [['*' if f == 1 or r > 2 else '.'] * c for _ in range(r)]
        res[0][0] = 'c'
        
        def fill(r0, r1, c0, c1, s = '.'):
            for i in range(r0, r1):
                for j in range(c0, c1):
                    res[i][j] = s
        
        if f == 1:
            return res
        if r == 1:
            fill(0, 1, c-m, c, '*')            
        elif r == 2:
            if m % 2 != 0 or f == 2:
                return None
            fill(0, 2, c-m//2, c, '*')            
        else:
            if f in [2, 3, 5, 7]:
                return None
            if f % 2 == 0 and f <= 2 * r:
                fill(0, f // 2, 0, 2)
            elif f % 2 == 1 and f <= 2 * r + 1:
                fill(0, (f-3) // 2, 0, 2)
                fill(0, 3, 2, 3)
            else:
                q = f // r
                p = f % r
                fill(0, r, 0, q)
                fill(0, p, q, q+1)
                if p == 1:
                    res[1][q] = '.'
                    res[r-1][q-1] = '*'
            res[0][0] = 'c'             
        return res
    
    r, c, m = nums()    
    if r > c:
        res = do(c, r, m)
        if res:
            res = zip(*res)
    else:
        res = do(r, c, m)
    if res:
        return '\n' + '\n'.join(''.join(x) for x in res)
    else:
        return '\nImpossible'
    
       
        
def main():
    fname = 'c.in'
    if len(sys.argv) > 1:
        fname = sys.argv[1]    
    fin = io.open(fname)
    fout = io.open(fname + '.out', 'w')
    t0 = datetime.datetime.now()    
    t = int(fin.readline())
    
    for i in range(t):
        fout.write('Case #%d: ' % (i + 1))
        fout.write('%s\n' % str(solve(fin)))
    
    print('Time = %s' % str(datetime.datetime.now() - t0))
    fin.close()
    fout.close()
        
if __name__ == '__main__':
    main()    