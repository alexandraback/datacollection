def f(s):
    if set(list(s))==set(["+"]):
        return 0
    i=0
    while i<len(s) and s[i] == s[0]:
        i+=1
    sN = i*("-" if (s[0]=="+") else "+")+s[i:]
    return f(sN)+1
lines = open("panin.txt").read().splitlines()
out = ""
for i in xrange(1, len(lines)):
    out+="Case #"+str(i)+": "+str(f(lines[i]))+"\n"
open("panout.txt","w").write(out)

