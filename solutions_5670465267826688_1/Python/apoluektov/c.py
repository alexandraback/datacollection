import sys
from collections import defaultdict

def line():
    return sys.stdin.readline().strip()

def ints(s):
    return [int(t) for t in s.split()]


dd = {}
dd[('i','j')] = 'k'
dd[('j','k')] = 'i'
dd[('k','i')] = 'j'

def mult(c1,c2):
    if c1 == '1':
        return (1,c2)
    if c1 == c2:
        return (-1,'1')
    
    if (c1,c2) in dd:
        return (1,dd[(c1,c2)])
    else:
        return (-1,dd[(c2,c1)])


def solve(s0,x0):
    x = x0 % 4
    if x + 4 <= x0:
        x += 4


    ss = x*s0
    
    st = 'ijk'
    idx = 0

#    print '\n'
#    print ss

    s,c = 1,'1'
    for cn in ss:
        sn,c = mult(c,cn)
        s *= sn

#        if s == 1:
#            print c
#        else:
#            print '-' + c


        if idx < 2:
            if s == 1 and c == st[idx]:
 #               print '---'
                c = '1'
                idx += 1

    if s == 1 and c == st[idx]:
        return 'YES'
    else:
        return 'NO'
        

def main():
    tc = int(line())
    for i in range(1,tc+1):
        l,x = ints(line())
        s = line()
        print 'Case #%s: %s' % (i, solve(s,x))

main()
