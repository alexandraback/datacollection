def sol(a,b,c,d):
    pairs1 = {}
    pairs2 = {}
    pairs3 = {}

    outfits = []

    for i in range(1,a+1):
        for j in range(1,b+1):
            for k in range(1,c+1):
                valid = True
                if (i,j) in pairs1:
                    if pairs1[(i,j)] >= d:
                        valid = False
                if (i,k) in pairs2:
                    if pairs2[(i,k)] >= d:
                        valid = False
                if (j,k) in pairs3:
                    if pairs3[(j,k)] >= d:
                        valid = False

                if valid:
                    outfits.append((i,j,k))
                    if (i,j) in pairs1:
                        pairs1[(i,j)] += 1
                    else:
                        pairs1[(i,j)] = 1
                    if (i,k) in pairs2:
                        pairs2[(i,k)] += 1
                    else:
                        pairs2[(i,k)] = 1
                    if (j,k) in pairs3:
                        pairs3[(j,k)] += 1
                    else:
                        pairs3[(j,k)] = 1
    print(pairs1, pairs2, pairs3)
    sol = str(len(outfits))+"\n"
    for o in outfits:
        sol += str(o[0])+" "+str(o[1])+" "+str(o[2])+"\n"
    return sol

            



fIn = open('input.txt', 'r')
fOut = open('output.txt', 'w')
case = 0
for line in fIn:
    print(case)
    if case > 0:
        j = int(line.split(" ")[0])
        p = int(line.split(" ")[1])
        s = int(line.split(" ")[2])
        k = int(line.split(" ")[3])
        fOut.write("Case #"+str(case)+": "+sol(j,p,s,k))
    case += 1