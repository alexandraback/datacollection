T = int(raw_input())
for i in range(T):
    S = list(raw_input())
    front = [S[0]]
    back = []
    for c in S[1:]:
        if c >= front[-1]:
            front.append(c)
        else:
            back.append(c)
    print "Case #%d: %s" % (i+1, "".join(reversed(front)) + "".join(back))