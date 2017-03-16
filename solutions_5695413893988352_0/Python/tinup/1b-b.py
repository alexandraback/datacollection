import sys
#sys.stdout = open("out.txt", "w")
def matc(n,s):
    n = str(n)
    n = (len(s)-len(n))*"0"+n
    for i in range(len(s)):
        if s[i]!='?':
            if s[i]!=n[i]:
                return False
    return True


def solve(c,j):
    l=len(c)
    pc = set()
    pj = set()
    for i in range(10**l):
        if matc(i,c):
            pc.add(i)
        if matc(i,j):
            pj.add(i)
    diff = 10000000
    ans = (10000,10000)
    for cs in pc:
        for js in pj:
            if diff>=abs(js-cs):
                if diff>abs(js-cs):
                    diff = abs(js-cs)
                    ans=(cs,js)
                elif ans[0]>cs:
                    ans = (cs,js)
                elif ans[1]>js:
                    ans = (cs,js)
    ac,aj = ans[0],ans[1]
    ac = str(ac)
    ac = (l-len(ac))*"0"+ac
    aj = str(aj)
    aj = (l-len(aj))*"0"+aj
    return ac + " "+ aj
                     
        
            
        
    
    


lines = []

with open("B-small-attempt0.in", "r") as f:
    lines = f.readlines()

n = int(lines[0])
l=""
for i in range(1, n+1):
    x =  lines[i].strip().split()
    c,j = x[0],x[1]
    ans = solve(c,j)
    l+="Case #{}: {}\n".format(i, str(ans))

with open("out.txt","w") as f:
    f.write(l)
