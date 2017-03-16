tt = int(raw_input())
for t in xrange(1, tt+1):
    n = int(raw_input())
    if n == 0:
        ans = 'INSOMNIA'
    else:
        digit = [0] * 10
        digitfound = 0
        i = 1
        while True:
            num = i * n
            ncc = num
            while num > 0:
                d = num % 10
                if digit[d] == 0:
                    digit[d] = 1
                    digitfound += 1
                num /= 10
            if digitfound == 10:
                ans = str(ncc)
                break
            i += 1
    print 'Case #%d: %s' % (t, ans)