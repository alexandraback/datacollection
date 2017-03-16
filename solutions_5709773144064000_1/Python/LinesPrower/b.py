'''
Created on Apr 12, 2014

@author: linesprower
'''
import io, sys
import datetime
import math

def solve(fin):
    def nums():
        return [int(x) for x in fin.readline().split()]
    def fnums():
        return [float(x) for x in fin.readline().split()]
    def num():
        return int(fin.readline())
    
    c, f, x = fnums()
    last = x / 2
    farms = max(0, math.floor(x / c) - 5)
    step = 0
    while True:        
        cur = 0
        s = 2.0
        for _ in range(farms):
            cur += c / s
            s += f
        cur += x / s        
        if cur > last:
            print('%d farms, step = %d' % (farms, step))
            assert(step > 1 or farms < 2)
            return "%.7f" % last
        last = cur
        farms += 1
        step += 1   
        
def main():
    fname = 'b.in'
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