def kcn(k, c, s):
    if k == 1:
        return 1

    if c == 1:
        if k > s:
            return 'IMPOSSIBLE'
        else:
            return ' '.join(str(i) for i in xrange(1, k+1))

    if s <= k - 2:
        return 'IMPOSSIBLE'
    else:
        return ' '.join(str(i) for i in xrange(2, k + 1))

lines = raw_input()
for question_index in xrange(1, int(lines) + 1):
    k, c, s = [int(s) for s in raw_input().split(" ")]
    print "Case #{}: {}".format(question_index, kcn(k, c, s))