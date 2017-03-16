__author__ = 'bszikszai'

def simulate(j, p, s, k):
    res = ""
    jp = {}
    ps = {}
    js = {}
    tot = {}
    ctr = 0
    while True:
        found = False
        for ji in range(0, j):
            for pi in range(0, p):
                for si in range(0, s):
                    jpi = ji*p + pi
                    psi = pi*s + si
                    jsi = ji*s + si
                    toti = ji*p*s + pi * s + si
                    if not(jpi in jp):
                        jp[jpi] = 0
                    if not(psi in ps):
                        ps[psi] = 0
                    if not(jsi in js):
                        js[jsi] = 0
                    if not(toti in tot):
                        tot[toti] = 0
                    if jp[jpi] < k and ps[psi] < k and js[jsi] < k and tot[toti] == 0:
                        found = True
                        res = res + "%s %s %s\n" % (ji+1, pi+1, si+1)
                        jp[jpi] = jp[jpi] + 1
                        ps[psi] = ps[psi] + 1
                        js[jsi] = js[jsi] + 1
                        tot[toti] += 1
                        ctr += 1
        if not found:
            return str(ctr)+"\n"+res.rstrip('\n')

def solve(f):
    inp = [int(x) for x in f.readline().rstrip('\n\r ').split(' ')]
    return simulate(inp[0], inp[1], inp[2], inp[3])

with open('input.txt', 'r') as f:
    with open('output.txt', 'wb') as g:
        cases = int(f.readline())
        for i in range(0, cases):
            solution = solve(f)
            print "Case #%s: %s" % (i+1, solution)
            g.write("Case #%s: %s\n" % (i+1, solution))