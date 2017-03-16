f = open("A-large.in", 'r')
allfile = f.read()
lines = allfile.split("\n")
output = []

def maxmin(scores, i):
    allGood = False
    Yi = 0
    notincluded = [i]
    S = sum(scores)
    N = len(scores)
    while not allGood:
        Na = N - len(notincluded)
        sumA = sum([scores[j] for j in notincluded])
        Yi = (-1.0*score - 1.0*sumA/Na + 2.0*S/Na) / (S + 1.0*S/Na)
        Xk = (-1.0*sumA + 1.0*S * (2-Yi)) / Na
        allGood = True
        for k in xrange(len(scores)):
            if Xk < scores[k] and k not in notincluded:
                notincluded.append(k)
                allGood = False
        print S, N, Na, sumA, Yi, Xk, allGood
    if Yi < 0:
        Yi = 0.0
    return Yi

T = int(lines.pop(0))
for Tcount in xrange(T):
    line = lines.pop(0)
    split = line.split(" ")
    N = split[0]
    scores = [int(split[n]) for n in xrange(1, len(split))]
    S = sum(scores)
    out = []
    for i in xrange(len(scores)):
        score = scores[i]
        fraction = maxmin(scores, i)
        out.append(float(fraction*100))
    output.append(out)

f = open("problemA.out", 'w')
def outProcess(out):
    temp = ""
    for i in out:
        temp += " " + str(i)
    return temp
for x in xrange(len(output)):
    out = "Case #" + str(x+1) + ":" + outProcess(output[x]) + "\n"
    f.write(out)
    print(out)
