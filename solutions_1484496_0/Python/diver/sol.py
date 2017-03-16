inf = open("C-small-attempt2.in")
outf = open("C-small-attempt2.out", "w")

numTests = int(inf.readline().rstrip())

def processAll(a):
    n = len(a)
    sums = dict()
    for i in range(1 << n):
        s = 0
        for j in range(n):
            if (i >> j) & 1:
                s += a[j]
        if s in sums:
            return sums[s], i
        sums[s] = i
    return None
def printSet(a, mask):
    items = []
    for j in range(len(a)):
        if (mask >> j) & 1:
            items.append(str(a[j]))
    return " ".join(items)

def getAnswer(a):
    res = processAll(a)
    if res is None:
        return "\nImpossible"
    return "\n" + printSet(a, res[0]) + "\n" + printSet(a, res[1])

for test in range(numTests):
    a = list(map(int, inf.readline().split()))[1:]
    print("Case #%d: %s" % (test + 1, getAnswer(a)), file=outf)

