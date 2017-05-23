infile  = open("B-large.in", "r")
outfile = open("B-large.out","w")
cases = int(infile.readline().strip())
for o in range(1,cases+1):
    d = infile.readline().strip()
    p = infile.readline().strip().split()
    p = map(int,p)
    e = max(p)
    m = 2
    while (m < e):
        q = sum([(x - 1) // m for x in p]) + m
        e = min(e,q)
        m += 1
    outfile.write("Case #%s: %s\r\n" % (o,e))
infile.close()
outfile.close()