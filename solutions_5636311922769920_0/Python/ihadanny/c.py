import sys

    
T = int(sys.stdin.readline())
case = 1
for line in sys.stdin:
    s = line.strip()
    if len(s) > 0:
        K,C,S = map(int, s.split())
        res = []
        for i in range(K):
            sum = 1
            mult = 1
            for c in range(C):                
                sum += i * mult
                mult *= K
                #print "K", K, "i", i, "c", c, "sum", sum
            res.append(sum)
        print "Case #{0}:".format(case), ' '.join(map(str, res))
        case += 1


