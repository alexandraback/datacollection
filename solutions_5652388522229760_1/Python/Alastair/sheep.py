def max_y(n):
    if n==0:
        return "INSOMNIA"
    y=0
    dig=set()
    full = set([str(i) for i in xrange(10)])
    while dig != full:
        y+=n
        dig = dig.union(list(str(y)))
    return str(y)

lines = open("sheepin.txt").read().splitlines()
out = ""
for i in xrange(1, len(lines)):
    out+="Case #"+str(i)+": "+max_y(int(lines[i]))+"\n"
open("sheepout.txt","w").write(out)
