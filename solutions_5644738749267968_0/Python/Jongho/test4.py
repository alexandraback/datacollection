def deceit(a,b,len):
    cnt=0
    a_start,a_end=0,len-1
    b_start,b_end=0,len-1
    while b_end>=b_start and a_end>=a_start:
        if a[a_start]<b[b_start]:
            a_start+=1
            b_end-=1
        else:
            cnt+=1
            a_start+=1
            b_start+=1
    return cnt  

def war(a,b,len):
    cnt=0
    a_start,a_end=0,len-1
    b_start,b_end=0,len-1
    while b_end>=b_start:
        if a[a_end]>b[b_end]:
            cnt+=1
            a_end-=1
            b_start+=1
        else:
            a_end-=1
            b_end-=1
    return cnt  

cases = int(raw_input())
for count in xrange(cases):
    blocks=int(raw_input())
    naomi = map(float,raw_input().split())
    ken = map(float,raw_input().split())

    naomi.sort()
    ken.sort()
    #print naomi
    #print ken
    warres=war(naomi,ken,blocks)
    deceitres=deceit(naomi,ken,blocks)

    print "Case #%d: %d %d" % (count+1,deceitres,warres)
    
