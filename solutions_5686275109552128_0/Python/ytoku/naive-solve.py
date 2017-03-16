import sys

def solve(l, depth):
    l = filter(lambda x: x > 0, l)

    if len(l) == 0:
        return 0
    if depth == 0:
        return 10000
    
    n = 1 + solve(map(lambda x: x - 1, l), depth - 1)
    result = n

    l2 = sorted(l)
    x = l2.pop()
    for i in range(1, x/2 + 1):
        l3 = list(l2)
        l3.append(i)
        l3.append(x - i)
        n = 1 + solve(l3, depth - 1)
        result = min(result, n)

    return result
    
T = int(sys.stdin.readline())
for _c in range(T):
    D = int(sys.stdin.readline())
    line = sys.stdin.readline().strip()
    P = map(int, line.split(" "))
    #print P
    print "Case #%d: %d" % (_c + 1, solve(P, max(P)))
