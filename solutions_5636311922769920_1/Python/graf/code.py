import sys

def get_index(ind, base):
    ans = 0
    for t in ind:
      ans = ans * base + t
    return ans + 1

def solve_test(inp):
    pattern, levels, s = map(int, inp.readline().split())
    if pattern  > levels * s:
        return 'IMPOSSIBLE'
    to_test = list(range(pattern))
    ans = []
    while to_test:
      ind = to_test[:levels]
      to_test = to_test[levels:]
      ans.append(get_index(ind, pattern))
    return ' '.join([str(x) for x in ans])

inp = open(sys.argv[1])
out = open(sys.argv[1].rsplit('.',1)[0]+'.out', 'w')
n_tests = int(inp.readline())
for i in range(n_tests):
    ans = solve_test(inp)
    print("Case #%d: " % (i+1) + ans, file=out)
out.close()