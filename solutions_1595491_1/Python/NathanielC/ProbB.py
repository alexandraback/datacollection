def top(n):
    return (n+2)/3

# n - total score
# returns (max, larger?)
#   where larger is true iff can use a surprise to make it bigger
def max_val(n):
    v = top(n)
    l = (n+2>3*v) and v>=1
    return (v,l)


# l - line of input
def process(l):
    ln = [int(s) for s in l.split()]
    N = ln[0]
    S = ln[1]
    p = ln[2]
    d = ln[3:]

    cnt = 0

    for googler in d:
        m = max_val(googler)
        if m[0]>=p:
            cnt+=1
            continue
        elif m[0]+1==p and m[1] and S:
            S-=1
            cnt+=1
    return cnt


f = open("in")
out = open("out",'w')
l = f.readlines()

for i in xrange(1,int(l[0])+1):
    out.write("Case #"+str(i)+": "+str(process(l[i].strip()))+"\n")

f.close()
out.close()
