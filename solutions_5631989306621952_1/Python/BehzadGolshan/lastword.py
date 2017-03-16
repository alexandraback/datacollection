n = int(raw_input())
for itt in xrange(n):
    word = raw_input().strip()
    res = word[0]
    for l in word[1:]:
        if l < res[0]:
            res = res + l
        else:
            res = l + res
    # solving the problem
    print 'Case #' + str(itt + 1) + ': ' + res#str(num * 2)
