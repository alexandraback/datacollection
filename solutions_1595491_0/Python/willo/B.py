from operator import itemgetter, attrgetter
import itertools
import os, logging

FILE = 'B-small-1'

def runner():
    path = os.path.join(os.path.dirname(__file__), '%s.in' % FILE)
    f = open(path, 'r')
	
    path = os.path.join(os.path.dirname(__file__), '%s.out' % FILE)
    r = open(path, 'w')
	
    for n, test_case in enumerate(f.readlines()[1:]):
        l = test_case.split()
        N = l[0]
        S = l[1]
        p = l[2]        
        t = l[3:]
        
        result = process(N, S, p, t)

        #		if result == None: result = 'NO'
        s = 'Case #%r: %s\n' % (n + 1, result)
        print s
        r.write(s)
	
    f.close()
    r.close()
	

def process(N, S, p, t):
    # N number of googlers
    # S surprising triplets
    # p hurdle
    # t list(total points per Googler)
    
    # pass N

    r = 0
    S = int(S)
    p = int(p)

    # 8, 8, 8 -> 9, 8, 7
    # 8, 8, 7 -> 9, 7, 7
    # 8, 7, 7 -> 8, 8, 6
    
    for total_score in t:
        total_score = int(total_score)
        base = total_score / 3
        mod = total_score % 3
        high_score = base + min(1, mod)
        
        inc = 0
        if (base * 3) + 1 == total_score:
            pass
        elif high_score == 10:
            pass
        elif high_score + 1 > total_score:
            pass
        else:
            inc = 1
        
        
        if high_score >= p:
            r += 1
        elif S and inc and high_score + inc >= p:
            r += 1
            S -= 1
        
    return r


if __name__ == "__main__":
	#import doctest
	#doctest.testmod()
	runner()

