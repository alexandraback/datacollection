t = input()
nu = ["ZERO", "ONE", "TWO", "THREE", "FOUR", "FIVE", "SIX", "SEVEN", "EIGHT", "NINE"]
cnt = [0]*10

def remove(num, sig):
    word = nu[num]
    cnt = dic.get(sig, 0)
    if cnt > 0:
        for c in word:
            dic[c] -= cnt
    return cnt
for t in xrange(t):
    s = raw_input()
    dic = {}
    for c in s:
        dic[c] = dic.get(c, 0) + 1

    # first
    cnt[0] = remove(0, "Z")
    cnt[2] = remove(2, "W")
    cnt[4] = remove(4, "U")
    cnt[6] = remove(6, "X")
    cnt[8] = remove(8, "G")

    # second
    cnt[1] = remove(1, "O")
    cnt[3] = remove(3, "T")
    cnt[5] = remove(5, "F")
    cnt[7] = remove(7, "S")

    # third
    cnt[9] = remove(9, "I")

    res = "".join(str(i)*cnt[i] for i in xrange(10) if cnt[i])
    print "Case #%d: %s" % (t+1, res)
    for k in dic:
        if dic[k] != 0:
            print s
            print k, dic[k]
            exit(1)

