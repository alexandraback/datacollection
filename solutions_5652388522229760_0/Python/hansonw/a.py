T = int(raw_input())

for i in range(T):
    N = int(raw_input())
    print 'Case #%d:' % (i + 1),
    if N == 0:
        print 'INSOMNIA'
    else:
        n = 1
        ok = [False] * 10
        done = 0
        while True:
            digits = str(n * N)
            for c in digits:
                ch = ord(c) - ord('0')
                if not ok[ch]:
                    ok[ch] = True
                    done += 1
            if done == 10:
                print n * N
                break
            n += 1
