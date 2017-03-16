filename = raw_input("Enter the name of the input file: ")
f = open(filename, 'r')
outfile = open("outfile.txt", 'w')
t = int(f.readline())
for case in range(t):
    x = [int(i) for i in f.readline().split()]
    n = x.pop(0)
    xset = set(x)
    xdict = {i : set([i]) for i in xset}
    outfile.write("Case #" + str(case + 1) + ":\n")
    done = False
    xnewdict = xdict
    for i in range(n):
        xmiddict = xnewdict
        xnewdict = {}
        for total, subset in xmiddict.items():
            for j in xset:
                if not j in subset and j > max(subset):
                    if total + j in xdict:
                        for k in subset:
                            outfile.write(str(k) + ' ')
                        outfile.write(str(j))
                        outfile.write('\n')
                        print xdict[total+j]
                        for k in xdict[total + j]:
                            outfile.write(str(k) + ' ')
                        outfile.write('\n')
                        done = True
                        break
                    else:
                        xnewdict[total + j] = subset.union([j])
            if done:
                break
        if done:
            break
        else:
            xdict = dict(xdict.items() + xnewdict.items())
    if not done:
        outfile.write("Impossible\n")
outfile.close()
    

