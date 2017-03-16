T = int(raw_input())

for case in xrange(1, T+1):
    stack = raw_input()

    current = stack[0]
    flips = 0
    for p_cake in stack[1:]:
        if p_cake != current:
            current = p_cake
            flips += 1

    flips += 1 if stack[-1] == '-' else 0
    print "Case #" + str(case) + ": " + str(flips)
