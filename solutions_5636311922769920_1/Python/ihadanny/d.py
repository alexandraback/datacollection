import sys

    
T = int(sys.stdin.readline())
case = 1
for line in sys.stdin:
    s = line.strip()
    if len(s) > 0:
        K,C,S = map(int, s.split())
        res = []
        offset = 1
        while True:
            sum = 1
            mult = 1
            for c in range(C):                
                sum += (min(offset, K)-1) * mult
                mult *= K
                #print "K", K, "c", c, "offset", offset
                offset += 1
            res.append(sum)
            if offset > K:
                break
        #print res
        if len(res) <= S:
            print "Case #{0}:".format(case), ' '.join(map(str, res))
        else:
            print "Case #{0}:".format(case), "IMPOSSIBLE"
        case += 1


