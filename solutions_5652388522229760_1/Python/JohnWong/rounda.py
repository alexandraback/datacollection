fn = "sample.txt"
debug = False

def process(num, n):
    s = set()

    for i in xrange(1, 100):
        t = n * i
        if debug:
            print('t', t)
        s.add(t % 10)
        t /= 10
        while t > 0:
            s.add(t % 10)
            t /= 10
            pass

        if len(s) == 10:
            print('Case #' + str(num) + ': ' + str(n * i))
            return
        pass
    print('Case #' + str(num) + ': INSOMNIA')

with open(fn) as f:
    n = int(f.readline()[:-1])
    if debug:
        print('count: ' + n)
    for i in range(1, n + 1):
        line = f.readline()[:-1]
        process(i, int(line))
        pass
    pass

