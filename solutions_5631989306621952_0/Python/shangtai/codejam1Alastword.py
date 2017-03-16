T = int(raw_input())
for i in xrange(T):
    S=raw_input()
    ourstring=S[0]
    for s in S[1:]:
        if s>=ourstring[0]:
            ourstring=s+ourstring
        else:
            ourstring=ourstring+s
    print("Case #{}: {}".format(i+1, ourstring))