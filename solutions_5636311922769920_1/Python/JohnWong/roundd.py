import math

fn = "sample.in"
debug = False


def process(N, K, C, S):
    if C * S < K:
        print('Case #' + str(N) + ': IMPOSSIBLE')
        return

    r = []
    for i in range(0, int(math.ceil(K * 1.0 / C))):
        s = range(C * i + 1, min(K, C * (i + 1)) + 1)
        if debug:
            print(s)
        tmp = 0
        cnt = 0
        for j in range(len(s) - 2, -1, -1):
            if s[j] > 1:
                cnt += 1
                tmp += (s[j] - 1) * K ** cnt
                pass
            pass
        tmp += s[-1]
        r.append(tmp)
        pass
    print('Case #' + str(N) + ': ' + ' '.join(map(str, r)))
    pass

# process(1, 4, 2, 2)
# process(1, 3, 2, 3)
# process(0, 3, 3, 1)

with open(fn) as f:
    n = int(f.readline()[:-1])
    if debug:
        print('count: ' + n)
    for i in range(1, n + 1):
        line = f.readline()
        if line.rfind('\n') > 0:
            line = line[:-1]
            pass
        sp = line.split(' ')
        process(i, int(sp[0]), int(sp[1]), int(sp[2]))
        pass
    pass

