

def recurcount(starts, ends, i, subs):
    if i==len(subs):
        return 0
    start=subs[i][0]
    end=subs[i][1]
    a=recurcount(starts,ends,i+1, subs)
    if starts[start]>1 and ends[end]>1:
        starts[start]-=1
        ends[end]-=1
        b=1 + recurcount(starts,ends,i+1,subs)
        starts[start]+=1
        ends[end]+=1
        return max(a,b)
    return a


t=int(input())
for i in range (t):
    n=int(input())
    starts={}
    ends={}
    subs=[]
    for j in range(n):
        line1=input().split()
        subs.append(line1)
        try:
            starts[line1[0]]+=1
        except:
            starts[line1[0]]=1
        try:
            ends[line1[1]]+=1
        except:
            ends[line1[1]]=1
    """
    print ("words: " + str(words))
    print ("startwords: " + str(startwords))
    print ("endwords: " + str(endwords))
    """
    print ("Case #" + str(i+1) + ": " + str(recurcount(starts,ends,0,subs)))
    
