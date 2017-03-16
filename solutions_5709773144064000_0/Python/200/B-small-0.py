from sys import stdin, stdout

def time_cost(C, F, X, m):
    cost = 0
    for n in xrange(m):
      cost += C / (2 + n * F)
    cost += X / (2 + m * F)
    return cost

T = int(stdin.readline())
for i in xrange(1, T + 1):
    args = stdin.readline().strip().split(' ')
    C = float(args[0])
    F = float(args[1])
    X = float(args[2])
    minFarm = 0
    maxFarm = int(X / C)
    last_cost = X / 2 + 1
    for m in xrange(maxFarm + 1):
        current_cost = time_cost(C, F, X, m)
        if current_cost > last_cost:
            break
        else:
            last_cost = current_cost
    stdout.write('Case #%d: %.7f\n' % (i, last_cost))