#! /usr/bin/env python

def solve_osmos(a,n, motes):
    motes = sorted(motes)
    operations = 0
    max_operations = n
    if a > 1: 
        for i,mote in enumerate(motes):
            if mote < a:
               a+= mote
               tmp_max_operations = operations + (n-i-1)
               if tmp_max_operations < max_operations:
                   max_operations = tmp_max_operations 
            else:
               while a <= mote:
                   a += a-1
                   operations += 1
               a += mote
            if operations >= max_operations:
               break
    else:
         return n      
    return operations if operations < max_operations else max_operations

t = input()
for i in xrange(1, t+1):
    a,n = raw_input().split()
    a = int(a)
    n = int(n)
    motes = [int(j) for j in raw_input().split()]
    print 'Case #%d: %d' % (i, solve_osmos(a,n, motes))

