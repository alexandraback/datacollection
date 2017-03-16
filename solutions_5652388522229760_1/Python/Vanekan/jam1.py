t = input()

for tc in range(1, t+1):
    n = input()
    if n == 0:
        print "Case #%d: INSOMNIA" % tc
    else:
        l = [0,0,0,0,0,0,0,0,0,0]
        i = 0
        while l <> [1,1,1,1,1,1,1,1,1,1]:
            i = i + 1
            k = i * n
            while k <> 0:
                l[k%10] = 1
                k = k / 10

        print "Case #%d: %d" % (tc,i*n)