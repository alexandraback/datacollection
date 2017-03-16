t=input()
for i in range(t):
    n=input()
    ma=[]
    for j in range(((2*n)-1)):
        v= [int(s) for s in raw_input().split(" ")] 
        for k in v:
            si = set(ma)
            if k in si:
                 ma.remove(k)
            else:
                ma.append(k)
    print "Case #"+str((i+1))+":",
    for val in sorted(ma):
        print val,
    print ""
