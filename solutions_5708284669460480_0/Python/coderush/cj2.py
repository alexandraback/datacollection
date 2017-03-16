def overlaplength(s):
    ret=0
    for i in xrange(1,len(s)):
        if s[0:i]==s[len(s)-i:]:
            ret=i
    return s[ret:]
import sys
f=open("input.txt",'r')
f1=open("output.txt",'w')
sys.stdin=f
sys.stdout=f1


t=int(raw_input())
for test in xrange(t):
    k,l,s=map(int,raw_input().split())
    keys=list(str(raw_input()))
    target=list(str(raw_input()))
    #print keys,set(keys)
    #print target,set(target)
    #print (set(target) not in set(keys))
    if (set(target) & set(keys))!=set(target) or s<l:
        print "Case #"+str(test+1)+': 0.0'
        continue
    else:
        d_keys={}
        for i in keys:
            if d_keys.has_key(i):
                d_keys[i]+=1
            else:
                d_keys[i]=1
        prob=1.0
        for i in target:
            #print i,d_keys[i],k
            prob*=(d_keys[i]+0.0)/k
        #print prob,"prob"

        maxtimes=(s-l)/len(overlaplength(target)) +1
        print "Case #"+str(test+1)+": "+str(maxtimes*(1-prob))
                
    
    
f.close()
f1.close()
