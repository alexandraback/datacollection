
# -*- coding: cp932 -*-

import sys

def debug(msg):
    #return
    sys.stderr.write(msg)
    sys.stderr.flush()
    

def gcd(a, b):
        if b == 0:
                return a
        else:
                return gcd(b, a % b)
def lcm(a, b):
        return a * b / gcd(a, b)


def isPowerOf2(n):
    return (n - 1) & n == 0  

def solve(s,b):
    if not isPowerOf2(b):
        return "impossible"
    
    t = b
    ans = 0
    while t > s:
        t = t >> 1
        ans += 1
    
    return str(ans)

inputfile = "A-large.in"
f = open(inputfile)
sys.stdout = open(inputfile.replace(".in", ".txt"),'w')
tc_num = int(f.readline().rstrip())

for tc in range(tc_num):
    l = f.readline().split("/")
    s = int(l[0])
    b = int(l[1])
    #debug(str(s))
    #debug(str(b))
    d = gcd(s,b)
    
    ans = solve(s // d,b // d)
    
    print("Case #" + str(tc+1) + ": " + ans)

   
