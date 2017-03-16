from itertools import chain
from itertools import combinations 
from sets import Set
import sys
import math    

def init():
    out = open(sys.argv[2], 'w')
    f = open(sys.argv[1], 'r')
    test_cases = []
    ans = []
    f.readline()
    for line in f:
        tmp = line.split(" ")
        cont = []
        dict = {}
        tmp.pop(0);
        total = 0;
        x  = powerset(tmp)
        sums  = {}
        suc = False
        for ps in x:
	   s = 0
           for inte in ps:
              s += int(inte)
           if(s in sums):
              ans.append((ps, sums[s]))
              suc = True
              break
           else:
              sums[s] = ps
        if(suc == False):
           ans.add(false)
         
          
    ind = 1
    for a in ans: 
        out.write("Case #" + str(ind) +": ")
        out.write("\n")

        if a == False:
        	out.write("Impossible")
                out.write("\n")
        else:
             count = 0
             for integer in a[0]:
                if count > 0:
                   out.write(" ") 
             	out.write(str(int(integer)))
		count +=1
             out.write("\n")
             count = 0
             for integer in a[1]:
                if count > 0:
                   out.write(" ") 
             	out.write(str(int(integer)))
		count +=1
             out.write("\n")
        ind +=1

def powerset(iterable):
    "powerset([1,2,3]) --> () (1,) (2,) (3,) (1,2) (1,3) (2,3) (1,2,3)"
    s = list(iterable)
    return chain.from_iterable(combinations(s, r) for r in range(len(s)+1)) 

init()
