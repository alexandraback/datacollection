T = int(raw_input())

for i in xrange(T):
    N = int(raw_input())
    result = ""
    solderList = []
    d = dict()
    for j in xrange(2 * N - 1):
        for k in [int(x) for x in raw_input().split()]:
            d[k] = d.get(k,0) + 1
    for (k,v) in d.items():
        if v % 2 == 1:
            solderList.append(k)
    solderList.sort()
    print "Case #"+ str(i+1) + ": " + " ".join([str(x) for x in solderList])
