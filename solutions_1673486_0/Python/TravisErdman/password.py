myFile = open("A-small-attempt0.in", "r")

ABli = list()
Pli = list()
T = None

for myLine in myFile:
    if not T:
        T = int(myLine)   #number of test cases
    elif len(ABli) == len(Pli):
        li = myLine.split()
        ABli.append([int(x) for x in li])
    else:
        li = myLine.split()
        Pli.append([float(x) for x in li])

myFile.close()

outputFile = open('password.out','w')
for casenum,([A,B],Ps) in enumerate(zip(ABli,Pli)):
    #calculate expectation
    cumprob = 1.0
    minEV = 2*B
    Ps.append(1.0)
    for i,p in enumerate(Ps):
        EV = (A-i+B-i+1)*cumprob + (1-cumprob) * (A-i + B-i+1 + B+1)
        minEV = min(minEV,EV)
        cumprob *= p
    result = float(min(minEV,B+2))

    outputFile.write('Case #'+str(casenum+1)+': '+str(result)+'\n')
    outputFile.flush()

outputFile.close()
