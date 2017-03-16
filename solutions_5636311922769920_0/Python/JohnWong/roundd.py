import math

fn = "sample.in"
debug = False

def process(N, K, C, S):
    result = []
    for x in xrange(1, K + 1):
        result.append(x)
        pass
    while C > 1:
        C -= 1
        for x in range(len(result)):
            result[x] = K * (result[x] - 1) + x + 1
            pass
        pass
    print('Case #' + str(N) + ': ' + ' '.join(map(str, result)))
    
    pass

# process(1, 3, 3, 3)

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

