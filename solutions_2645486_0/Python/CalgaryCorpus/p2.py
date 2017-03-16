from math import sqrt

def maxz( e, E, R, start, v, mem ):
    # print " "
    # print " " * start, e, start, v
    if start >= len(v): return 0

    if e > E:
        e = E


    k = "%s:%s" % (start,e)
    if k in mem:
      return mem[k]

    max = 0
    for i in range(e+1):
        val = v[start]*i + maxz(e-i+R,E,R,start+1,v,mem)
        if val > max:
          max = val

    mem[k] = max
    return max

def transform():
    mem = {}
    values = raw_input().split()
    E = int( values[0] )
    R = int( values[1] ) 
    N = int( values[2] )
    values = raw_input().split()
    v = []
    for i in range(len(values)):
      v.append( int(values[i]) );

    result = maxz( E, E, R, 0, v, mem )

    return result

# main()

n = int( input() )

for i in range(n):
    t = transform()
    print "Case #"+str(i+1) + ":", t

