import math

fn = "sample.in"
debug = False


def primeDivisor(n):
    if n < 3:
        return 0
    s = int(math.sqrt(n))
    for i in range(2, s + 1):
        if n % i == 0:
            return i
        pass
    return 0

def process(N, J):
    print('Case #1:')
    for x in xrange(2 ** (N - 1) + 1, 2 ** N):
        if x % 2 == 0:
            continue
        result = []
        candi = bin(x)[2:]
        for y in xrange(2, 11):
            ret = primeDivisor(int(candi, y))
            if ret > 0:
                result.append(str(ret))
            else:
                break
        if len(result) == 9:
            print(candi + ' ' + (' '.join(result)))
            J -= 1
            if J == 0:
                return;
            pass
        pass
    pass

# process(6, 3)

with open(fn) as f:
    n = int(f.readline()[:-1])
    if debug:
        print('count: ' + n)
    for i in range(1, n + 1):
        line = f.readline()
        if line.rfind('\n') > 0:
            line = line[:-1]
        sp = line.split(' ')
        process(int(sp[0]), int(sp[1]))
        pass
    pass
    print('')

