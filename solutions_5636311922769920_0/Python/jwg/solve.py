def recurse(K, C, index):
    if index > K:
        index = K
    if C == 1:
        return index
    return (index-1)*(K**(C-1)) + recurse(K, C-1, index+1)

def solve(K, C, S):
    reveals = []
    #known is an index of the original string O such that 
    #we know the first k elements of O contains only L's
    known = 0
    while len(reveals) < S and known < K:
        #branch = known
        #tile = 0
        #for depth in range(C):
        #    tile += branch * ((C-depth)**K)
        #    branch += 1
        #reveals.append(tile)
        rec = recurse(K, C, known+1)
        if rec > (K**C):
            rec = (K**C)
            reveals.append(rec)
            return reveals
        reveals.append(rec)
        known += (C)

    if known < K:
        return False
    return reveals




numCases = input()
for case in range(1, numCases+1):
    K, C, S = map(int, raw_input().split(" "))
    ans = solve(K, C, S)
    print "Case #%d: %s" % (case, " ".join(map(str, ans)) if ans else "IMPOSSIBLE")
