T = input()

def rank():
    N = input()
    m = {}
    arr = []
    for i in range( 2 * N - 1):
        line = [int(x) for x in raw_input().strip().split(' ')]
        for x in line:
            if x not in m:
                m[x] = 1
            else:
                m[x] += 1
    for k, v in m.items():
        if v % 2 == 1:
            arr.append(k)
    arr.sort()
    return ' '.join([str(x) for x in arr])

for i in range(1, T + 1):
    ans = rank()
    print "Case #%d: %s" % (i, ans)