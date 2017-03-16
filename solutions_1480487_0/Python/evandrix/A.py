import sys
import time
import math

if __name__ == "__main__":
    t0 = time.time()
    _i = open("/Users/lwy08/Downloads/A-small-attempt6.in", "r")
    _o = open("/Users/lwy08/Downloads/A.out", "w")
    T = int(_i.readline())
    for _t in xrange(T):
        line = _i.readline().split()
        N = int(line[0])
        S = map(int, line[1:])
        total_s = sum(S)
        total_final_points = 2 * total_s

        required = []
        too_good = []
        s_prime = []
        for i,x in enumerate(S):
            if x > total_final_points / float(N):
                too_good.append((i,x))
            else:
                s_prime.append((i,x))

        s_prime_sum = sum([x for i,x in s_prime])
        mean = s_prime_sum / float(len(s_prime)) + (sum(S) / float(len(s_prime)))
        
        for n in xrange(N):
            found = False
            the_thing = None
            for item in s_prime:
                i, x = item
                if i == n:
                    found = True
                    the_thing = x
            if found:
                difference = (mean - the_thing) / float(sum(S))                
                required.append(difference*100)
            else:
                required.append(0.0)

        result = "Case #%d: %s" % (_t + 1, ' '.join(map(str, required)))
        print result
        print >> _o, result
    _i.close()
    _o.close()
    #print >> sys.stderr, "%lf seconds" % (time.time() - t0)
