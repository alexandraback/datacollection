import sys

def sums(comb, mask, l):
    sub = []
    for i in xrange(l):
        if ((mask & (1<<i)) > 0):
            sub.append(comb[i])

def solve(j, p, s, k):
    usedps = dict()
    usedjs = dict()
    usedjp = dict()
    cp = 0
    cs = 0
    ans = []
    for cj in xrange(j):
        np = cp
        for op in xrange(p):
            ns = cs
            for os in xrange(s):
                ps = usedps.get(((cp+op)%p, (cs+os)%s), 0)
                js = usedjs.get((cj, (cs+os)%s), 0)
                jp = usedjp.get((cj, (cp+op)%p), 0)
                if (ps<k and js<k and jp<k):
                    usedps[((cp+op)%p, (cs+os)%s)] = ps+1
                    usedjs[(cj, (cs+os)%s)] = js+1
                    usedjp[(cj, (cp+op)%p)] = jp+1
                    ans.append("%d %d %d" % (cj+1, (cp+op)%p+1, (cs+os)%s+1))
                    np = (cp+op)%p+1
                    ns = (cs+os)%s+1
            cs = ns
        cp = np
    return ("%d\n" % len(ans)) + "\n".join(ans)

#input_filename = sys.argv[1]
input_filename = "C-small-attempt0.in"#"in.txt" 

with open(input_filename, "r") as infile:
    with open("out.txt", "w") as outfile:
        tnum = int(infile.readline())
        for t in xrange(tnum):
            J, P, S, K = map(int, infile.readline().split())
            ans = solve(J, P, S, K)
            outfile.write("Case #%d: %s\n" % (t+1, ans))
            print (t+1, ans)
        