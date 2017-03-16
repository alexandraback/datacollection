f = [line.rstrip() for line in open('/Users/roshil/Desktop/B-small-attempt0 (3).in')]
out = open('/Users/roshil/Desktop/out.txt','w')
out.truncate()
line = 0
testcases = int(f[line])
line += 1
for i in range(1,testcases+1):
    n = int(f[line])
    line += 1
    l = []
    d = {}
    for j in range(2*n-1):
        new_list = [int(k) for k in f[line].split()]
        for m in new_list:
            try:
                d[m] += 1
            except:
                d[m] = 1
        line += 1
    ans = []
    for o in d.keys():
        if d[o]%2 == 1:
            ans.append(o)
    ans.sort()
    ans = " ".join([str(p) for p in ans])
    print ans
    out.write("Case #"+str(i)+": "+ str(ans) + "\n")
out.close()