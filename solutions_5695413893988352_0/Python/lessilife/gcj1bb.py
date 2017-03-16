import re

min_diff=int(2**31-1)
min_cj=""

def dfs(cj,left):
    global min_diff,min_cj
    if left==0:
        (c,j)=cj.split()
        (c,j)=map(int,(c,j))
        if abs(c-j)<min_diff:
            min_diff=int(abs(c-j))
            min_cj=cj
    if left<=0: return
    for i in xrange(10):
        dfs(re.sub('\?',str(i),cj,count=1),left-1)

t=input()
for ti in xrange(t):
    min_diff=int(2**31-1)
    cj=raw_input()
    dfs(cj,len(re.findall('\?',cj)))
    print("Case #%d: %s"%(ti+1,min_cj))
