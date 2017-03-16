from operator import itemgetter, attrgetter
import itertools
import os, logging

FILE = 'C-large-0'

def runner():
    path = os.path.join(os.path.dirname(__file__), '%s.in' % FILE)
    f = open(path, 'r')
	
    path = os.path.join(os.path.dirname(__file__), '%s.out' % FILE)
    r = open(path, 'w')
	
    for n, test_case in enumerate(f.readlines()[1:]):
        l = test_case.split()
        A = l[0]
        B = l[1]
        result = process(A,B)


        s = 'Case #%r: %s\n' % (n + 1, result)
        print s
        r.write(s)
	
    f.close()
    r.close()
	

def process(A,B):

    int_A = int(A)
    int_B = int(B)

    r = 0

    s = set()

    for n in xrange(1, len(B)):
        for o in xrange(int_A, int_B):
            O = str(o)
            possible = int(O[n:] + O[:n])
            #print o, O[n:], O[:n]
            if possible <= int_B and possible >= int_A and possible != o and possible > o:
                
                t = (o, possible)
                
                if t not in s:
                    r += 1
                    s.add(t)
                
                #print o, possible

    #print s

    return r
    
    
    


if __name__ == "__main__":
	#import doctest
	#doctest.testmod()
	runner()

