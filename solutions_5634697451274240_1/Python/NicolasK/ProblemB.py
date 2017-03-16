s = open("salida.txt", 'w')
f = open("B-large.in")

cases = int(f.readline())
for case in xrange(1,cases+1):

    panqueques = f.readline()
    panqueques = panqueques.strip("\n")
    flips = 0
    for c in xrange(len(panqueques)-1):
        if panqueques[c] != panqueques[c+1]:
            flips += 1
    print panqueques
    print flips
    print panqueques[len(panqueques)-1] == "-"
    s.write("Case #" + str(case) + ": " + str(flips+(panqueques[len(panqueques)-1] == "-"))+"\n")
f.close()
s.close()