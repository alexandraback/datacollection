
# -*- coding: cp932 -*-

import sys

def debug(msg):
    #return
    sys.stderr.write(msg)
    sys.stderr.flush()
    

def f33(k):
    if k >= 5:
        return k-1
    else:
        return k

def f34(k):
    if k >= 8:
        return k-2
    else:
        return f33(k)
 
def f35(k):
    if k >= 11:
        return k-3
    else:
        return f34(k)

def f36(k):
    if k >= 14:
        return k-4
    else:
        return f35(k)
    
def f44(k):
    if k >= 12:
        return k-4
    elif k >= 10:
        return k-3
    else:
        return f34(k)
    
def f45(k):
    if k >= 16:
        return k-6
    elif k >= 14:
        return k-5
    else:
        return f44(k)
    
   
    
def solve(n,m,k):
    if n < 3:
        return k
    
    if n == 3:
        if m == 3: return f33(k)
        elif m == 4: return f34(k)
        elif m == 5: return f35(k)
        elif m == 6: return f36(k)
    elif n == 4:
        if m == 4: return f44(k)
        elif m == 5: return f45(k)
        
    return -1

inputfile = "C-small-attempt0.in"
f = open(inputfile)
sys.stdout = open(inputfile.replace(".in", ".txt"),'w')
tc_num = int(f.readline().rstrip())

for tc in range(tc_num):
    l = f.readline().split()
    n = int(l[0])
    m = int(l[1])
    k = int(l[2])
    ans = solve(min(n,m),max(n,m),k)
    print("Case #" + str(tc+1) + ": " + str(ans))

   
