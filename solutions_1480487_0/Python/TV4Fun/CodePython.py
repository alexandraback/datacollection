filename = raw_input("Enter the name of the input file: ")
f = open(filename, 'r')
outfile = open("outfile.txt", 'w')
t = int(f.readline())
for case in range(t):
    x = [int(i) for i in f.readline().split()]
    n = x.pop(0)
    xsum = sum(x)
    outfile.write('Case #' + str(case + 1) + ':')
    minscore = 2.0 * xsum / n
    changed = True
    maylose = x[:]
    while changed:
        changed = False
        for i in maylose:
            if i > minscore:
                maylose.remove(i)
                if len(maylose) > 1:
                    minscore = (float(sum(maylose)) + xsum) / len(maylose)
                    changed = True

    print minscore

    for i in x:
        if i >= minscore:
            outfile.write(' 0.0')
        else:
            outfile.write(' ' + str(100.0 * float(minscore - i) / xsum))

    outfile.write('\n')
outfile.close()
    

