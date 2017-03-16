inp = open('1.test')

T = int(inp.readline().rstrip())
for t in range(1,T+1):
    N = inp.readline().rstrip()

    count = 0
    while True:
        if len(N) == 1:
            answer = count + int(N)
            break
        else:
            shl = (len(N))//2
            msq = '0'*(shl-1) + '1'

            # print N, count,

            nn = N[:len(N)-shl] + msq
            while int(nn) > int(N):
                # print nn,
                nn = str(int(nn) - int(msq[::-1]+'0'))

            # print nn
            rn = nn[::-1]
            nextN = '9'*(len(rn)-1)

            if nextN == '':
                nextN = '0'
            count += int(N) - int(nn) + int(rn) -  int(nextN)

            if rn != nn:
                count += 1

            N = nextN

    print 'Case #%d: %d' % (t, answer)
