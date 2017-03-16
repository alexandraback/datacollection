with open("data.txt", 'r') as f:
    with open("data1.txt", 'w') as g:
        T = int(f.readline())
        for i in range(T):
            N = int(f.readline())
            if N == 0:
                g.write("Case #%d: INSOMNIA\n" % (i+1))
                continue
            digits = set()
            num = 0
            while True:
                num += N
                dig = list(str(num))
                for x in dig:
                    digits.add(x)
                if len(digits) == 10:
                    break
            g.write("Case #%d: %d\n" % ((i+1), num))
