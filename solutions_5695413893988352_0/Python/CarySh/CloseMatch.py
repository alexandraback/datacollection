__author__ = 'cary shindell'

inp = open("match.in", 'r')
opt = open("match.out", 'w')

N = None
scores = []
for line in inp:
    if N is None:
        N = int(line)
    else:
        if "\n" in line:
            line = line[:-1]
        l = line.split(" ")
        scores.append((l[0], l[1]))

results = []

for s in scores:
    C = s[0]
    J = s[1]
    baseC = ""
    baseJ = ""
    for n in C:
        if n == "?":
            baseC += "0"
        else:
            baseC += n
    for n2 in J:
        if n2 == "?":
            baseJ += "0"
        else:
            baseJ += n2
    digitposs = list([] for x in C)
    #Jdigit1poss = []
    ctr = 0
    for n in C:
        if C[ctr] == "?":
            if J[ctr] == "?":
                digitposs[ctr].extend([("0","0"), ("1","0"), ("0","1"), ("0","9"), ("9","0")])
            else:
                if J[ctr] != "0":
                    digitposs[ctr].append((str(int(J[ctr])-1), J[ctr]))
                    digitposs[ctr].append(("0", J[ctr]))
                if J[ctr] != "9":
                    digitposs[ctr].append((str(int(J[ctr])+1),J[ctr]))
                    digitposs[ctr].append(("9", J[ctr]))
                digitposs[ctr].append((J[ctr], J[ctr]))
        elif J[ctr] == "?":
            if C[ctr] == "?":
                digitposs[ctr].extend([("0","0"), ("1","0"), ("0","1"), ("0","9"), ("9","0")])
            else:
                if C[ctr] != "0":
                    digitposs[ctr].append((C[ctr], str(int(C[ctr])-1)))
                    digitposs[ctr].append((C[ctr], "0"))
                if C[ctr] != "9":
                    digitposs[ctr].append((C[ctr],str(int(C[ctr])+1)))
                    digitposs[ctr].append((C[ctr], "9"))
                digitposs[ctr].append((C[ctr], C[ctr]))
        else:
            digitposs[ctr].append((C[ctr], J[ctr]))
        ctr += 1
    testnumC = ""
    testnumJ = ""
    bestdiff = None
    bestnums = []
    print digitposs
    for x in digitposs[0]:
        #testnumC += x[0]
        #testnumJ += x[1]
        if len(digitposs) > 1:
            for y in digitposs[1]:
                #testnumC += y[0]
                #testnumJ += y[1]
                if len(digitposs) > 2:
                    for z in digitposs[2]:
                        testnumC = x[0] + y[0] + z[0]
                        testnumJ = x[1] + y[1] + z[1]
                        diff = abs(int(testnumC) - int(testnumJ))
                        if bestdiff is None or diff <= bestdiff:
                            bestdiff = diff
                            bestnums.append((int(testnumC), int(testnumJ)))
                else:
                    testnumC = x[0] + y[0]
                    testnumJ = x[1] + y[1]
                    diff = abs(int(testnumC) - int(testnumJ))
                    if bestdiff is None or diff <= bestdiff:
                        bestdiff = diff
                        bestnums.append((int(testnumC), int(testnumJ)))
        else:
            testnumC = x[0]
            testnumJ = x[1]
            diff = abs(int(testnumC) - int(testnumJ))
            if bestdiff is None or diff <= bestdiff:
                bestdiff = diff
                bestnums.append((int(testnumC), int(testnumJ)))
    print bestnums
    for nums in bestnums[:]:
        if abs(nums[0] - nums[1]) != bestdiff:
            bestnums.remove(nums)
    Cs = list(n[0] for n in bestnums)
    minC = min(Cs)
    for nums2 in bestnums[:]:
        if nums2[0] > minC:
            bestnums.remove(nums2)
    Js = list(n[1] for n in bestnums)
    minJ = min(Js)
    for nums3 in bestnums[:]:
        if nums3[1] > minJ:
            bestnums.remove(nums3)
    numC = str(bestnums[0][0])
    numJ = str(bestnums[0][1])
    while len(numC) < len(C):
        numC = "0" + numC
    while len(numJ) < len(C):
        numJ = "0" + numJ
    results.append((numC, numJ))

ctr = 1
for d in results:
    opt.write("Case #" + str(ctr) + ": " + d[0] + " " + d[1] + "\n")
    ctr += 1

inp.close()
opt.close()