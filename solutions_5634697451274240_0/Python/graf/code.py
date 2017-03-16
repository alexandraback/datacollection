import sys

def solve_test(inp):
    x = inp.readline().strip()
    x += '+'
    ans = sum(a!=b for a, b in zip(x, x[1:]))
    return str(ans)

inp = open(sys.argv[1])
out = open(sys.argv[1].rsplit('.',1)[0]+'.out', 'w')
n_tests = int(inp.readline())
for i in range(n_tests):
    ans = solve_test(inp)
    print("Case #%d: " % (i+1) + ans, file=out)
out.close()