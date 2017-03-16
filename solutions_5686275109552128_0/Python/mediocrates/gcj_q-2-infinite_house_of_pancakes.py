results = {}

def insert_sorted(L, x):
    ind = sum([1 for z in L if z > x])
    L.insert(ind, x)
    return L

def pancakes(L, t):

    if tuple(L) in results:
        return t + results[tuple(L)]

    if L == []:
        if tuple(L) not in results:
            results[tuple(L)] = 1
        return t+1

    if L[0] == 2:
        if tuple(L) not in results:
            results[tuple(L)] = 2
        return t+2

    ans = L[0]
    best = []
    for x in range(2,L[0]/2+1):
        y = L[0] - x
        M = L[1:]
        M.insert(sum([1 for z in M if z > x]), x)
        M.insert(sum([1 for z in M if z > y]), y)
        # print "calling pancakes on splitL", M
        # print "calling pancakes(", M, ")", t+1, range(2,(L[0]/2+1)), ans
        ans1 = pancakes(M, t+1)
        if tuple(M) not in results:
            results[tuple(M)] = ans1
        if ans1 < ans:
            ans = min(ans, ans1)
            best = M[:]

    # print "The best split for", L, "is", best
    if tuple(L) not in results:
        results[tuple(L)] = ans
    return t + ans



f = open('B-small-attempt1.in','r+b')
# g = open('output.txt', 'w')
T = int(f.readline().strip())

for c in range(1,T+1):

    D = int(f.readline().strip())
    P = sorted(map(int, f.readline().strip().split()), reverse=True)
    # assert len(P) == D, "Something went wrong."
    # print "####################"
    # print "%-3d 0 %s" % (c, str(P))
    # g.write("###################\n%-3d 0 %s\n" % (c,str(P)))

    # print "hello"
    P = [p for p in P if p != 1]
    ans = pancakes(P, 0)
    # print "goodbye"

    print "Case #%d: %d" % (c, ans)
    # g.write("Case #%d: %d\n" % (c, ans))


f.close()
# g.close()