import os,sys

def GetTriplets(value):
    p = value / 3
    ans = []
    for i in xrange(p-2,p+3):
        if i<0 or i>10:
            continue
        for j in xrange(p-2,p+3):
            if j<0 or j>10:
                continue
            for k in xrange(p-2,p+3):
                if k<0 or k>10:
                    continue
                if i>j or j>k or i>k:
                    continue
                if i+2<k or i+j+k!=value:
                    continue
                ans.append((i,j,k,"Yes" if i+2==k else "No"))
    return {one[3]:one[2] for one in ans}
Dic ={}
for i in xrange(0,31):
    Dic[i] = GetTriplets(i)
T = int(raw_input())
for tt in xrange(0,T):
    buff = raw_input()
    arr = map(int,buff.split(' '))
    n,s,p = arr[0:3]
    val = arr[3:len(arr)]
    ans = 0
    for one in val:
        if Dic[one]['No'] >= p:
            ans += 1
        elif Dic[one].get('Yes',-1) >= p and s:
            ans += 1
            s -= 1
    print "Case #%d: %d" %(tt+1,ans)
