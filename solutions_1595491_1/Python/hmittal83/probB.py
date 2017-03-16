import math

def apart2(i, j, k):
    a1 = math.fabs(i - j);
    a2 = math.fabs(i - k);
    a3 = math.fabs(j - k);
    if (a1 > 2 or a2 > 2 or a3 > 2):
        return 2
    elif (a1 == 2 or a2 == 2 or a3 == 2):
        return 1
    else:
        return 0

def possibleSums():
    sumArr = []
    for i in range(31):
        sumArr.append([])
    for i in range(11):
        for j in range(11):
            for k in range(11):
                val = apart2(i, j, k)
                if (val != 2):
                    mysum = i + j + k
                    struct = [i, j, k], val
                    sumArr[mysum].append(struct)
    return sumArr


def maxNonSur(ti):
    return (ti + 2)/3

def maxSur(ti):
    if (ti == 0):
        return 0
    if (ti == 1):
        return 1
    return (ti + 4)/3


def main():
    line = raw_input()
    t = int(line)
    for cntr in range(t):
        line = raw_input()
        nlist = map(int, line.split(" "))
        N = nlist[0]
        S = nlist[1]
        p = nlist[2]
        list_ti = [(x, maxNonSur(x), maxSur(x)) for x in nlist[3:]]
        count = 0
        for it in list_ti:
            a,b,c = it
            if (b >= p):
                count += 1
                continue
            if (c >= p and S > 0):
                count += 1
                S -= 1
                continue
        disp = cntr + 1
        print "Case #%d: %d" % (disp,count)
main()
