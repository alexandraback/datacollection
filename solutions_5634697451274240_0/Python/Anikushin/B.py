import sys
    
with open("out.txt", "w") as fout:
    with open("B.in", "r") as f:
      n = int(f.readline())
      for i in xrange(n):
        s = f.readline().strip() + "+"
        k = 0
        print s
        res = []
        for x in range(len(s)-1):
            if s[x] != s[x+1]:
                res.append(x)
                k+=1
        print res
        fout.write("Case #%d: %d\n" % (i+1, k))