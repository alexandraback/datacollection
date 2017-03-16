import sys
f = open('A_sm.in')
#f = sys.stdin
cases = int(f.readline())

def search_ten(nu):
    ten = 1
    while ten < nu:
        ten = ten*10
    return ten/10
    
def reverse(nu):
    return int(str(nu)[::-1])

def solve(nu):
    if nu < 10:
        return nu
    s = str(nu)
    h = len(s)/2
    if len(s) % 2 == 0:
        x =  reverse(int(s[:h])) + int(s[h:])
        y = nu - (10 ** (len(s)-1))
        return min(x,y)
    else:
        x = reverse(int(s[:h])) + int(s[h+1:]) + int(s[h])*(10**h) 
        y = nu -  (10 ** (len(s)-1))
        return min(x,y)
    
def driver(nux):
    nu = nux
    if nu < 19:
        return nu
    ctr = 0
    if int(str(nu)[-1]) == 0:
        ctr = ctr + 1
        nu -= 1
    ctr += solve(nu)
    nu = search_ten(nu)
    while(nu > 1):
        ctr += solve(nu -1)
        ctr += 1
        nu = search_ten(nu) 
    return ctr

for case in range(cases):
    print "Case #"+str(case+1)+ ": "+str(driver(int(f.readline())))
