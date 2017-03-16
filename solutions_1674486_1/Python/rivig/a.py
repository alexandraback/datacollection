import sys, string

debug = False

# memoizing successor set calculation
def calcsucc(i, inh, allsucc):
    if allsucc[i] is None:
        succ = set([i])
        for j in range(len(inh[i])):
            k = inh[i][j]
            calcsucc(k, inh, allsucc)
            succ.update(allsucc[k])
            succ.add(k)
        allsucc[i] = succ

def diamond(n, inh):
    if debug:
        print "Data"
        for i in range(n):
            print "%d: %s" % (i, " ".join(map(str, inh[i])))
    allsucc = [None] * n
    for i in range(n):
        calcsucc(i, inh, allsucc)
    if debug:
        print "Succ"
        for i in range(n):
            print "%d: %s" % (i, " ".join(map(str, allsucc[i])))
    for i in range(n):
        for j in range(len(inh[i])):
            nodej = inh[i][j]
            succj = allsucc[nodej]

            for k in range(len(inh[i])):
                if k == j: continue
                nodek = inh[i][k]
                succk = allsucc[nodek]
                if succj & succk:
                    if debug:
                        print "Node %d, succsessors %d (%s) and %d (%s), common %s" % (i, nodej, " ".join(map(str, succj)), nodek, " ".join(map(str, succk)), " ".join(map(str, succj & succk)))
                    return "Yes"
            
    return "No"

def main(args):
    f = file(args[1])
    ncases = int(f.readline())
    for ncase in range(ncases):
        line = f.readline().rstrip()
        n = int(line)
        inh = []
        for i in range(n):
            line = f.readline().rstrip()
            nums = map(int, line.split(" "))
            inh.append(map(lambda x: x-1, nums[1:]))
#        if ncase + 1 != 6: continue
        ans = diamond(n, inh)
        sys.stdout.write("Case #%d: %s\n" % (ncase+1, ans))

if __name__ == "__main__":
    main(sys.argv)