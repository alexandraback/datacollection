import sys

def solve_test(inp):
    x = int(inp.readline())
    if x==0:
        return 'INSOMNIA'
    seen = set()
    i = 0
    while len(seen) != 10:
        i += 1
        seen |= set(str(i * x))
        #print(len(seen))
    return str(i * x)    

inp = open(sys.argv[1])
out = open(sys.argv[1].rsplit('.',1)[0]+'.out', 'w')
n_tests = int(inp.readline())
for i in range(n_tests):
    ans = solve_test(inp)
    print("Case #%d: " % (i+1) + ans, file=out)
out.close()