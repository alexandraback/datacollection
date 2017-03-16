import sys
import math

file = open(sys.argv[1])
numcases = int(file.readline().rstrip())

#def foo(s,p,t):
#    result = 0
#    maybe = 0
#    for i in t:
#        if i == 0:
#            if p== 0:
#                result += 1
#            break
#        q,r = divmod(i,3)
#        if r == 0:
#            if p <= q:
#                result += 1
 #           elif p <= q+1:
 #               maybe += 1
 #       elif r == 2:
 #           if p <= q+1:
 #               result += 1
 #           elif p <= q+2:
  #              maybe += 1
  #      elif r == 1:
 #           if p <= q+1:
  #              result += 1
  #  
  #  return result + min(maybe,s)       

def foo(s,p,t):
    result = 0
    maybe = 0
    for i in t:
        if p == 1:
            if i == 0:
                continue
            else:
                result +=1
                continue
            
        if i >= 3*p-2:
            result += 1
        elif i >= 3*p-4:
            maybe += 1
    return result + min(maybe,s)

for i in xrange(numcases):
    values = file.readline().rstrip().split()
    numgooglers = int(values[0])
    s = int(values[1])
    p = int(values[2])
    t = map(int,values[3:])
    print "Case #{}: {}".format(i+1,foo(s,p,t))
