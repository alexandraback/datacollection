import math
def check(i):
    tmp = str(i)
#    print tmp
    if len(tmp)==1:
        return 1
    l = len(tmp)
    
    for i in range(l/2):
#        print tmp[i],tmp[l-i-1]
        if tmp[i] != tmp[l-i-1]:
            return 0

#    print tmp
    return 1

t = raw_input()
#print t
t = int(t)
for i in range(t):
    tmp = raw_input()
    a,b=map(int,tmp.split())
    s = int(math.sqrt(a))
    end = int(math.sqrt(b))
    if (s ** 2) <a:
        s = s+1
    if (end ** 2) <b:
        end = end +1
    cnt = 0
    #print s**2,end**2
    for ii in range(s,end+1):
        #print ii
        if (ii**2) > b:
            break
        if check(ii):
            if check(ii**2) == 1:
                cnt += 1
                print ii**2
    print "Case #%d: %d" %(i+1,cnt)
