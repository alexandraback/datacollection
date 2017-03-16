def subsets(cur=[],Sum=0,i=0):
    global found,ans
    if i == len(s):
        All[Sum].append(cur)
        if len(All[Sum]) >= 2:
            found = True
            ans = Sum
        
    elif not found:
        subsets(cur,Sum,i+1)
        subsets(cur+[s[i]],Sum+s[i],i+1)
        

data = open("P2.txt")
out = open("P2.out","w")
cases = int(data.readline())

for case in range(cases):
    info = map(int,data.readline().split())
    n = info[0]
    s = info[1:]
    All = [[] for z in range(sum(s)+1)]
    global found,ans
    found = False
    subsets()
    out.write("Case #%i:\n" %(case+1))
    
    #for i in range(len(All)):
        #print All[i]
        #if len(All[i]) >= 2:
    if found:
        a = All[ans][0]
        b = All[ans][1]
        
        out.write("%i" %(a[0]))
        for z in a[1:]:
            out.write(" %i" %(z))
        out.write("\n%i" %(b[0]))
        for z in b[1:]:
            out.write(" %i" %(z))
        out.write("\n")
    
    else:
        out.write("Impossible\n")