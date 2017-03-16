from operator import itemgetter
import re

with open('A-small-attempt-0.in') as f:
    num_cases = int(f.readline().replace('\n', ''))    
    for case in xrange(1, num_cases+1):    
        name, n = f.readline().replace('\n', '').split()
        n = int(n)
        
        comp = len(name)
        
        #print name, n
        p = re.compile('[^aeiou]+')
        nval = 0
        st = 0
        
        for m in p.finditer(name):
            stng = m.group()
            l = len(stng)

            if l < n:
                continue       
            #print stng, l, n, st

            sp = m.start() - st
            ep = sp + l
            
            comp = len(name) - st
            
            aval = ((l-n+1)*(l-n+2))/2
            bval =  sp*(comp-sp-n+1)
            cval =  (ep-n-sp+1)*(comp-ep)
            #print aval, bval, cval
            nval += aval + bval + cval 
            
            st += ep-n+1
        print 'Case #%d: %d' % ( case, nval )
