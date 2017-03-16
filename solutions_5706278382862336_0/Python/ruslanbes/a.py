from operator import itemgetter, attrgetter
from fractions import gcd

def output(t, res):
    casestr = "Case #" + str(t+1) +": "
    status = str(res) if res != None else "impossible"
    outputLine = casestr+status
    print outputLine

def isPowerOf2 (num):
    return num != 0 and ((num & (num - 1)) == 0)

def main():
    T = int( raw_input() )

    for t in xrange(T):            
        fr = raw_input()
        p, q = map(int, fr.split("/"))
        g = gcd(p, q)
        if g > 1:
            p /= g
            q /= g        
        if p <= q and isPowerOf2(q) and p % 2 == 1:
            q_bin = "{0:b}".format(q)
            p_bin = "{0:b}".format(p)
            if len(q_bin) >= 40:
                output(t, None)
            else:
                output(t, len(q_bin) - len(p_bin)) 
        else:    
            output(t, None)

if __name__ == "__main__":
   main()