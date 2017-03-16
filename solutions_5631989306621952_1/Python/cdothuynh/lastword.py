T = int(raw_input())

for t in xrange(T):
    S = raw_input()
    my_str = S[0]
    for s in S[1:]:
        if ord(s) >= ord(my_str[0]):
            my_str = s + my_str
        else:
            my_str = my_str + s
    print "Case #" + str(t+1) + ": " + my_str

