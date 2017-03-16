t = int(raw_input())
for case in range(1, t+1):
    b, m = map(int, raw_input().split(" "))
    if m > 2**(b-2):
        print "Case #%d: %s" % (case, "IMPOSSIBLE")
        continue
    print "Case #%d: %s" % (case, "POSSIBLE")
    array = [[0 for j in range(b)] for i in range(b)]
    for i in range(1, b-1):
        for j in range(i+1, b):
            array[i][j] = 1
    k = 0
    cur = m
    while cur > 0:
        if cur % 2 == 1:
            array[0][b-2-k] = 1
        cur /= 2
        k += 1
    # if highest power of 2, need to adjust
    if array[0][0] == 1:
        array[0][0] = 0
        for i in range(1, b):
            array[0][i] = 1
    for line in array:
        print "".join(map(str, line))
