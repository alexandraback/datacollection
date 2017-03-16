import sys

input = sys.stdin.read().split()
def pop_int():
    return int(input.pop(0))

def pop_str():
    return input.pop(0)

for t in xrange(pop_int()):
    K = pop_int()
    L = pop_int()
    S = pop_int()

    keyboard = pop_str()
    target = pop_str()

    occ = {}
    for k in keyboard:
        if k not in occ:
            occ[k] = 1
        else:
            occ[k] += 1

    if len(target) > S:
        r = 0.0
    elif any(ch not in keyboard for ch in target):
        r = 0.0
    else:
        u = 1
        while target[u:] != target[:-u]:
            u += 1

        max_ban = 1 + (S - len(target)) // u

        e1 = 1.0
        for ch in target:
            e1 *= float(occ.get(ch, 0)) / len(keyboard)
        exp_ban = e1 * (S - len(target) + 1)

        r = max_ban - exp_ban

    print 'Case #{}: {}'.format(t+1, r)
