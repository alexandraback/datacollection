def solve():

    if N==0:
        return 'INSOMNIA' 


    sd = set() 
    for i in xrange(1,100):
        ss = str(i*N)
        for c in ss:
            sd.add(int(c))
        # print ss, sd
        if len(sd) == 10:
            return ss

    raise Exception(N)

T = int(raw_input())

for i in range(T):
  N = int(raw_input())
  sol = solve()
  print "Case #%d: %s"%(i+1,sol)
