import sys, itertools

def checkElem(tt):
    ss = ""
    for i in range(len(tt)):
        if i == 0:
            last = tt[i]
            ss += last
        else:
            if tt[i] != last:
                ss += tt[i]
                last = tt[i]
    return ss

def precal(nn):
    rr = [1]
    cur = 1
    for i in range(1, nn+1):
        cur *= i
        rr.append(cur)
    return rr

def main():
    f = open(sys.argv[1], "r")
    t = int(f.readline().strip())

    f2 = open(sys.argv[2], "w")

    rr = precal(10)

    for i in range(t):
        f2.write("Case #"+str(i+1)+": ")

        n = int(f.readline().strip())
        line = f.readline().strip().split()

        ss = []
        
        flag = True
        for elem in line:
            tmpstr = checkElem(elem)
            ss.append(tmpstr)

        d = dict()
        for j in xrange(len(ss)):
            elem = ss[j]
            for c in elem:
               if not c in d:
                    d[c] = [j]
               else:            
                    if ss[j][-1] != c and ss[j][0] != c:
                        print ss[j]+" "+c
                        flag = False
                        break
                    if ss[d[c][0]][-1] != c and ss[d[c][0]][0] != c:
                        print ss[d[c][0]]+" "+c
                        flag = False
                        break
            if not flag:
                break

        if not flag:
            print str(i)+" early terminate"
            f2.write("0\n")
            continue
        
        res = 0

        ed = dict()
        for elem in ss:
            if not elem in ed:
                ed[elem] = 1
            else:
                ed[elem] += 1

        ss = []
        sup = 1
        for elem in ed:
            ss.append(elem)
            sup *= rr[ed[elem]]
    
        sup %= 1000000007
        pmobj = itertools.permutations(range(len(ss)))
        count = 0

        #print ss
        #print sup

        for it in pmobj:
            count += 1
            flag = True
            d = dict()
            tmpss = []
            for j in xrange(len(ss)):
                tmpss.append(ss[it[j]])
            for j in xrange(len(ss)):
                elem = ss[it[j]]
                for c in elem:
                    if not c in d:
                        d[c] = [j]
                    else:
                        if ss[it[j-1]][-1] != c or ss[it[j]][0] != c:
                            flag = False
                            break
                        if j - d[c][-1] > 1:
                            flag = False
                            break
                        d[c].append(j)
                if not flag:
                    break
            if flag:
                #print "case "+str(i+1)+": "+str(it)
                res += 1

        f2.write(str((res*sup) % 1000000007))
        print str(i)+" count="+str(count)
        f2.write("\n")

if __name__ == "__main__":
    main()
