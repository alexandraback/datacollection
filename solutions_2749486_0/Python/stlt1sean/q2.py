import sys, math
import pprint

def verify(s, x0, y0):
    x = 0
    y = 0
    i = 1
    for c in s:
        if c == 'S':
            y = y - i
        elif c == 'N':
            y = y + i
        elif c == 'W':
            x = x - i
        elif c == 'E':
            x = x + i
        else:
            return False
        i = i + 1
    if len(s) > 500:
        return False
    if (x0 != x) or (y0 != y):
        print x,y
        print x0,y0
        return False
    return True

def work(x,y):
    ret = ''
    if x > 0:
        ret = ret + 'WE'*x
    else:
        ret = ret + 'EW'*(-x)
        
    if y > 0:
        ret = ret + 'SN'*y
    else:
        ret = ret + 'NS'*(-y)
    return ret
    
if __name__=='__main__':
    fin = open('B-small-attempt0.in')
    #fin = open('b.in')
    fout = open('b.out','wt')
    #fout = sys.stdout
    line = fin.readline()
    t = int(line)
    for i in range(t):
        lines = fin.readline().strip().split()
        x = int(lines[0])
        y = int(lines[1])
        s = work(x,y)
        #print verify(s,x,y)
        fout.write('Case #%d: %s\n' %(i+1,s))
    fout.close()
