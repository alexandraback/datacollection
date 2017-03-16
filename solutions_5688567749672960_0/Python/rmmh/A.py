import sys

if len(sys.argv) == 1:
    sys.stdin = open(__file__.replace('.py', '.in'))
else:
    sys.stdin = open(sys.argv[1])
    sys.stdout = open(sys.argv[1].replace('.in', '') + '.out', 'w')

def get_ints():
    return map(int, raw_input().split())

n_cases = input()

costs = range(int(1e7))

for n, cost in enumerate(costs):
    if n == 1e7 - 1:
        break
    rev = int(str(n)[::-1])
    costs[n + 1] = min(costs[n + 1], cost + 1)
    costs[rev] = min(costs[rev], cost + 1)

for case in xrange(1, n_cases + 1):
    goal, = get_ints()

    print "Case #%d: %s" % (case, costs[goal])
