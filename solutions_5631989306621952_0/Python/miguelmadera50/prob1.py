def prob1(word):
    final = word[0]
    ch = word[0]

    for let in word[1:]:
        if let < final[0]:
            final = final + let
        else:
            final = let + final
    return final


t = int(raw_input())
for i in xrange(1, t + 1):
    n = raw_input()
    print "Case #{}: {}".format(i, prob1(n))
