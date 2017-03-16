from math import sqrt

def transform():
    values = raw_input().split()
    r = int( values[0] )
    t = int( values[1] ) 

    count = 0;
    c2p1 = count+1
    expresion = (2*r+1)
    if expresion <= t:
       l = 0
       right = sqrt(t)
       while l < right:
          count =  l + (int) (right-l)/2
          if l == count: break
          expresion1 = (2*r+1)*count; 
          expresion = expresion1 +2*(count-1)*count

          if expresion > t:
             right = count;
          elif expresion == t:
             l = count
             break
          else:
             l = count;
       count = l

    return count

# main()

n = int( input() )

for i in range(n):
    t = transform()
    print "Case #"+str(i+1) + ":", t

