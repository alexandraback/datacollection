output=[]
def fac(n):
    if n==0 or n==1 :
        return 1
    return n*fac(n-1)
t=int(raw_input())
for a0 in xrange(t):
    b,m=map(int,raw_input().split())
    
    if fac(b-1)<m:
        v=['IMPOSSIBLE',[]]
    else :
        v=['POSSIBLE']
        
        road=[]
        i=0
        while m>0 and i<b-1:
            road.append('0'*(i+1))
            j=i+1
            while j<b:
                if i==j:
                    road[i] +='0'
                else :
                    road[i]+='1'
                j=j+1
                
            i=i+1
            m=m-i
        while i<b-1:
            road.append('0'*b)
            i=i+1
            
        road.append('0'*b)
        
        
        v.append(road)
    output.append(v)

for i in xrange(len(output)):
    if output[i][0]=='POSSIBLE':
        print 'Case #'+str(i+1)+': POSSIBLE'
        for e in xrange(len(output[i][1])):
            print output[i][1][e]
    else :
        
        print 'Case #'+str(i+1)+': IMPOSSIBLE'
        
            
        
        
        
    
