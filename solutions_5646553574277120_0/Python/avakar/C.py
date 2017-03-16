import sys

input = sys.stdin.read().split()
def pop_int():
    return int(input.pop(0))

def add_coin(d, used, state):
    used |= (1<<d)
    state |= (state << d)
    return used, state

for t in xrange(pop_int()):
    C = pop_int()
    D = pop_int()
    V = pop_int()
    D = [pop_int() for i in xrange(D)]

    used = 1
    state = 1
    target = 2**(V+1) - 1

    for d in D:
        used, state = add_coin(d, used, state)

    q = [(used, state, 1, 0)]
    while q:
        used, state, next, dist = q.pop(0)
#        print bin(used), bin(state), next, dist
        if (state & target) == target:
            r = dist
            break

        essential = False
        while not essential:
            while used & (1<<next):
                next += 1
            essential = (state & (1<<next)) == 0
            u, s = add_coin(next, used, state)
            next += 1
            q.append((u, s, next, dist+1))

    print 'Case #{}: {}'.format(t+1, r)
