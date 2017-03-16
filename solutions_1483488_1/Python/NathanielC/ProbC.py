def rotate(s, i):
    return s[i:]+s[:i]

def cnt_pairs(A,B):
    S = set()
    S2 = set()
    cnt = 0
    for x in xrange(A,B+1):
        s = str(x)
        for i in xrange(1,len(s)):
            m=rotate(s,i)
            if m in S:
                S2.add((m,s))
                cnt+=1
        S.add(s)
    return len(S2)


f = open("in")
o = open("out",'w')

l = f.readlines()

for x in xrange(1,int(l[0])+1):
    r = [int(s) for s in l[x].split()]
    o.write("Case #"+str(x)+": "+str(cnt_pairs(r[0],r[1]))+"\n")

f.close()
o.close()
