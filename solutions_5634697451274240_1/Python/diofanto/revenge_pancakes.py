def aux_pancakes(p, n, side):
    if n < 0:
        return 0
    if p[n] == side:
        return aux_pancakes(p, n - 1, side)
    return 1 + aux_pancakes(p, n - 1, '+' if side == '-' else '-')

def pancakes(p):
    return aux_pancakes(p, len(p) - 1, '+')

for t in range(int(input())):
    print("Case #{0}: {1}".format(t+1, pancakes(input())))
