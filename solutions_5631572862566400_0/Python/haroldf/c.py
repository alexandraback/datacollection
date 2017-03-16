from collections import Counter
import itertools

def rec(x,ans):
    count=0
    for v in dct[x]:
        if v not in ans:
            count +=1
            #ans.add(v)
            ans.append(v)
            rec(v,ans)
    if count == 0:
        #if x in ans:
        ans.remove(x)     
    return ans

t = int(raw_input())
for case in xrange(1,t+1):
    N = int(raw_input())
    bff = map(int, raw_input().split())
    pairs = [[k,i] for k,i in zip(range(1,N+1),bff)]
    #lst1 = list(itertools.chain(*pairs))
    #lst2 = Counter(lst1)
    #lst3 = [k for k,v in lst2.iteritems() if v%2 !=0]
    # lst3 are the numbers with either 1 or >2 counts
    dct={}
    for j in range(1,N+1):
        dct[j] = []
    for k,i in pairs:
        dct[k].append(i)
        dct[i].append(k)
    #print dct
    
    track={}
    for i in xrange(1,N+1):
        ans = []
        ans= rec(i,ans)
        for x in dct[ans[-1]]:
            if x not in ans:
                ans.append(x)
                break
        
        track[i] = len(ans)
    print "Case #%s: %s" % (case,max(track.values()))