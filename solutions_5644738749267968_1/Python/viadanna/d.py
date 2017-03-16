import sys

inp = sys.stdin if len(sys.argv) == 1 else open(sys.argv[1])


def deceit(nao, ken):
    dp = 0
    while len(nao) > 0:
        if nao[-1] < ken[0]:
            return dp
        for i, nc in enumerate(nao):
            if nc > ken[0]:
                dp += 1
                nao.pop(i)
                break
        ken = ken[1:]
    return dp

for x in xrange(int(inp.readline())):
    n = int(inp.readline())
    nao = sorted(map(float, inp.readline().split()))
    ken = sorted(map(float, inp.readline().split()))
    wp, dp = 0, deceit(nao[:], ken[:])
    while len(nao) > 0:
        if nao[0] > ken[-1]:
            wp += len(nao)
            break
        nc = nao[0]
        for i, kc in enumerate(ken):
            if kc > nc:
                ken.pop(i)
                break
        nao = nao[1:]
        if len(nao) < len(ken):
            ken = ken[1:]
    print 'Case #%d: %d %d' % (x+1, dp, wp)

if inp != sys.stdin:
    inp.close()
