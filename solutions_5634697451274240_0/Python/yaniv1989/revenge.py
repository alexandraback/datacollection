import sys

def f(v):
    s = 1
    tot = 0
    for i in xrange(len(v)-1, -1, -1):
        if v[i]*s == -1:
            tot += 1
            s *= -1
    return tot
    
if __name__ == "__main__":
    if len(sys.argv) > 1:
        fname = sys.argv[1]
    else:
        fname = "in.txt"
    
    inp = open(fname, "rb").read()
    inp = inp.splitlines()[1:]
    inp = [x.rstrip() for x in inp]    
    
    d = {"+": 1,
         "-": -1}
    inp = [map(d.get, x) for x in inp]
    
    for i in xrange(len(inp)):        
        r = str(f(inp[i]))
        print "Case #%d: " % (i+1) + r
