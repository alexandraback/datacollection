import itertools

import re
REG=re.compile('[^aeiou]+')

def _fix(args):
    return list(args)+[0,]

def check(s,n):
    res=max( _fix( len(i) for i in REG.findall(s) ) )

    return res>=n

def subs(s):

    n=len(s)
    ran=range(n+1)
    for start,end in itertools.combinations_with_replacement(ran,2):
        yield(s[start:end])

def sol():

    ans=0
    s,n=raw_input().split()
    n=int(n)

    for i in subs(s):
        if check(i,n):
            ans+=1

    return ans

K=int(raw_input())
for i in range(K):
    print 'Case #{}: {}'.format(i+1,sol())
