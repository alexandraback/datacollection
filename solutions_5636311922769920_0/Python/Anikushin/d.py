import sys
    
with open("out.txt", "w") as fout:
    with open("d.in", "r") as f:
      T = int(f.readline())
      for t in xrange(T):
        k, c, s = map(int, f.readline().split())
        res = " ".join(map(str, range(1, s+1)))
        fout.write("case #%d: %s\n" % (t+1, res))
            
    
