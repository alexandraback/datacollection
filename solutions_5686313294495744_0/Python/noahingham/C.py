import math

def solve(l):
    d1 = {}
    d2 = {}
    r = 0
    for i in range(len(l)):
        if l[i][0] in d1:
            d1[l[i][0]]+=1
        else:
            d1[l[i][0]]=1
        if l[i][1] in d2:
            d2[l[i][1]]+=1
        else:
            d2[l[i][1]]=1
    s1=set()
    s2=set()
    for i in range(len(l)):
        #print l[i][0]+" "+l[i][1],
        if d1[l[i][0]]>1 and d2[l[i][1]]>1:
            s1.add(l[i][0])
            s2.add(l[i][1])
            #d1[l[i][0]]-=1
            #d2[l[i][1]]-=1
            #print "Cheater",
            r+=1
        #print ""
    return max(len(s1),len(s2))

if __name__ == "__main__":
    testcases = input()
    for caseNr in xrange(1, testcases+1):
        t = input()
        l=[]
    	for ll in xrange(1, t+1):
            li = raw_input()
            li = li.split(" ")
            l+=[(li[0],li[1])]
    	print("Case #%i: %s" % (caseNr, solve(l)))
