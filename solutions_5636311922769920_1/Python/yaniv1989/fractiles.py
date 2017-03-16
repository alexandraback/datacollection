import sys

def get_in_base(v, b):
    return sum([v[i]*(b**i) for i in xrange(len(v))])

def f(K, C, S):
    n = (K+C-1)/C
    if n > S:
        print "IMPOSSIBLE",
    else:
        last = 0
        for i in xrange(n):
            v = []
            for j in xrange(C):
                if last >= K:                    
                    break
                v.append(last)
                last += 1
            print get_in_base(v, K)+1,
        
if __name__ == "__main__":
    if len(sys.argv) > 1:
        fname = sys.argv[1]
    else:
        fname = "in.txt"
    
    inp = open(fname, "rb").read()
    inp = inp.splitlines()[1:]
    inp = [map(int, x.split()) for x in inp]

    for i in xrange(len(inp)):
        print "Case #%d:" % (i+1),
        f(*(inp[i]))
        print ""

