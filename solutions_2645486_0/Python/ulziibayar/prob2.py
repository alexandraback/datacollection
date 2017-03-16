from numpy import multiply, product
import math

def solve(En,R,N,vs):

   first = []
   second = []
   #print "En:{0},R:{1}, N:{2}, vs:{3}".format(En,R,N,vs)
   for i in range(En+1):
      
      first.append((En-i)*vs[0])
      #print "O({0},{1}) = {2}".format(0,i,(En-i)*vs[0]),
   #print " "
   #print "First: ",first
   for i in range(1,N):
      
      second=[]
      for p in range(En+1):
         s = []
         for e in range(En+1-p):
            index = max( min(p+e, En)-R,0)
            #print "Index:{0} i:{1}".format(index, i)
            s.append(first[index] + e*vs[i])
         
         val = max(s)
         second.append(val)
         
         #print "O({0},{1}): {2}".format(i,p, val),
      #print " "
      first = second
      
      assert(len(first)== En+1)
   if N==1:
      return first[0]
   else:
      return second[0]
    
    
    
def read():
    inp = "B-small-attempt2.in"
    out = "B-small-attempt2out.txt"
    f = open(inp, 'r')
    fo = open(out, 'w')
    num_lines = f.readline()
    for j in range(int(num_lines)):
        
        line1 = f.readline().replace("\n","").split(" ")
        line2 = f.readline().replace("\n","").split(" ")
        E = int(line1[0])
        R = int(line1[1])
        N = int(line1[2])
        vs = [int(i) for i in line2]
        
        result = solve(E,R,N,vs)
        print "Result is: ", result
        fo.write("Case #{0}: {1}".format(j+1,result))
           
        fo.write("\n")
read()
