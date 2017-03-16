fo = open("large.in", "r")

T = int(fo.readline())

for i in range(T):
    N = int(fo.readline())

    all = {}

    for a in range(2*N-1):
        nums = [int(b) for b in fo.readline().split()]

        for n in nums:
            all[n] = all.get(n, 0) + 1

    ans = []

    for x in all:
        if(all[x] % 2 == 1):
            ans.append(x)

    ans.sort()
    print 'Case #%d: %s' % (i+1, " ".join([str(a) for a in ans]))
