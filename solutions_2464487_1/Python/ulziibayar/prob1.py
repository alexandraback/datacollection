from numpy import multiply, product
import math

def solve(r,t):
   #print "R:{0}T:{1}".format(r,t)
   r = float(r)
   a = (2.0*r-1.0)
   t = float(t)
   val =  (-a+ math.sqrt(a*a +8.0*t))/4.0
   #print "Val is:", val
   return int(math.floor(val))
    
    
def read():
    inp = "A-large.in"
    out = "A-largeout.txt"
    f = open(inp, 'r')
    fo = open(out, 'w')
    num_lines = f.readline()
    for j in range(int(num_lines)):
        
        line1 = f.readline().replace("\n","").split(" ")
        r = int(line1[0])
        t = int(line1[1])
        
        result = solve(r,t)
        #print "Result is: ", result
        fo.write("Case #{0}: {1}".format(j+1,result))
           
        fo.write("\n")
read()
