T = int(raw_input())
for testcase in range(T):
    N = int(raw_input())
    digits = [False] * 10
    done = 0
    for mult in xrange(1,10000):
        s = str(mult * N)
        for c in s:
            c = ord(c) - ord('0')
            if not digits[c]:
                digits[c] = True
                done += 1
        if done == 10:
            print "Case #%d:" % (testcase+1), mult * N
            break

    else:
        print "Case #%d: INSOMNIA" % (testcase+1)
        
