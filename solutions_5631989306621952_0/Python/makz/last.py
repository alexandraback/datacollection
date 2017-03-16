for t in range(input()):
    print "Case #%s:" % str(t + 1),
    s = raw_input()
    # print s
    output = s[0]
    for c in s[1:]:
        if output[0] <= c:
            output = c + output
        else:
            output = output + c
    print output