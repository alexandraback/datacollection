T = int(input())
for tn in range(1, T + 1):
    N = int(input())
    if N == 0:
        print("Case #%d: INSOMNIA" % tn)
    else:
        done = [0] * 10
        alc = 0
        now = 0
        while alc < 10:
            now += N
            tmp = now
            while tmp > 0:
                d = tmp % 10
                tmp //= 10
                if not done[d]:
                    done[d] = 1
                    alc += 1
        print("Case #%d: %d" % (tn, now))

