t = input()

for tc in range(1, t+1):
    p = raw_input()
    a = []
    for i in list(p):
        if i == "-":
            a.append(0)
        else:
            a.append(1)
    state = 1
    flip = 0
    for i in a[::-1]:
        if i <> state:
            flip += 1
            state = 1 - state
    print "Case #%d: %d" % (tc,flip)