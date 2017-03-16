from itertools import *
from math import *
from functools import *

l=list(combinations_with_replacement(range(2,6),3))

ll=[]
for i in l:
    # print (i)
    lu=[reduce(lambda x,y:x*y,w) for w in product(i,repeat=3)]
    ll.append(lu)

# print (ll)
_=input()
_=input()
print ("Case #1:")
for i in range(100):
    a=map(int,input().split())
    for i in range(len(l)):
        if all(k in ll[i] for k in a):
            print ("".join(map(str,l[i])))
            break
    print ("222")
    
