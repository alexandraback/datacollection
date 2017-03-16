import sys
import itertools
 
def solve(C,J):
   qc = C.count("?")
   qj = J.count("?")
   minc = int("9"*len(C))+1
   minj = int("9"*len(J))+1
   mindiff = maxdiff = int("9"*len(C))+1
   sol = []

   for x in itertools.product("0123456789",repeat=qc):
       c = C
       # reemplazar en C
       for xx in x:
           c = c.replace("?",xx,1)
       # print C, "becomes", c

       prevdiff = maxdiff
       for y in itertools.product("0123456789",repeat=qj):
           j = J
           
           # reemplazar en J
           for yy in y:
               j = j.replace("?",yy,1)
           # print " "*10,J, "becomes", j

           ic = int(c)
           ij = int(j)
           diff = ic-ij
           if diff<0: diff = -diff
#           if diff > prevdiff: break
#           prevdiff = diff
           # print " "*30,diff,mindiff,sol
           if diff < mindiff:
              minc = ic
              minj = ij
              mindiff = diff
              sol = [c,j]
           elif diff == mindiff:
              if ic < minc:
                 minc = ic
                 minj = ij
                 sol = [c,j]
              elif ij < minj:
                 minc = ic
                 minj = ij
                 sol = [c,j]

   return " ".join(sol)
 
# main()
 
# read 1 number, use it to control the loop
for tc in xrange(1, int(sys.stdin.readline())+1):
    # read 2 numbers
    C,J = sys.stdin.readline().strip().split()
#    print "-"*80, C, J
    # read several floats, keep the result in a list
 
    best = solve(C,J)
    print 'Case #%d: %s' % (tc, best)
