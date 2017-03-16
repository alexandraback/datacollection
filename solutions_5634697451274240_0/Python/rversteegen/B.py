T = int(raw_input())
for testcase in range(T):
    pan = raw_input().strip()
    soln = 0
    for i in range(len(pan)-1, -1, -1):
        if pan[i] == '-':
            soln += 1
            pan2 = pan
            pan = ''
            for j in range(i+1):
                if pan2[j] == '+':
                    pan += '-'
                else:
                    pan += '+'
            pan += pan2[i+1:]
    print "Case #%d: %d" % (testcase+1, soln)
