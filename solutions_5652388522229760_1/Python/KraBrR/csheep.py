inp = open("A-large.in.txt", 'r')
out = open("large_output.txt", 'w')

ncase = int(inp.readline())

for cidx in range(ncase):
    bn = int(inp.readline())
    if bn == 0:
        out.write("Case #" + str(cidx+1) + ": INSOMNIA\n")
    else:
        counter = 1;
        nmap = set()
        while True:
            nstr = str(bn * counter)
            for c in nstr:
                nmap.add(c)
            # print str(cidx) + " " + str(nmap) + " " + str(counter)
            if len(nmap) == 10:
                out.write("Case #" + str(cidx+1) + ": " + nstr + "\n")
                break
            counter = counter + 1
