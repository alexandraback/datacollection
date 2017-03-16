infile  = open("A-small-attempt0.in", "r")
outfile = open("A-small-attempt0.out","w")
cases = int(infile.readline().strip())
for o in range(1,cases+1):
    l = infile.readline().strip()
    r = l.split(" ")
    sh,st,inv = (0,0,0)
    for au in r[1]:
        if int(au) > 0:
            if sh <= st:
                st += int(au)
            else:
                inv += (sh - st)
                st += inv + int(au)
        sh += 1
    outfile.write("Case #%s: %s\r\n" % (o,inv))
infile.close()
outfile.close()