T = int(raw_input().strip())

counts = [0, 1, 1, 2]
while len(counts) < 52:
    counts.append(sum(counts))


for i in xrange(1, T + 1):
    B, M = map(int, raw_input().strip().split())
    n = 1
    while n < 52 and n <= B and counts[n] < M:
        n += 1
    if n == 52 or n > B:
        print "Case #%s: %s" % (i, "IMPOSSIBLE")
        continue
    else:
        print "Case #%s: %s" % (i, "POSSIBLE")

    table = [[0 for _ in xrange(B)] for _2 in xrange(B)]
    n -= 1
    if n != 0:
        table[0][B - n] = 1

    for j in xrange(B - n, B - 1):
        for k in xrange(j + 1, B):
            table[j][k] = 1 

    if n == 0:
        table[0][B - 1] = 1
    else:
        curr = M - counts[n]
        ind = 51
        while curr > 0:
            while counts[ind] > curr or B - ind < B - n:
                ind -= 1
            table[0][B - ind -1] = 1
            curr -= counts[ind]

    for j in xrange(B):
        print "".join(map(str, table[j]))
