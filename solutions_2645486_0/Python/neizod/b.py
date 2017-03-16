#input = raw_input

def rerere(v, vs, e, E, R, t=0):
    if not vs:
        return t+v*e
    u, us = vs[0], vs[1:]
    return max(rerere(u, us, e-r+R, E, R, t+v*r) for r in range(R, e+1))

def find_it(E, R, values):
    v, vs = values[0], values[1:]
    return rerere(v, vs, E, E, R)

for case in range(int(input())):
    E, R, _ = [int(n) for n in input().split()]
    if R > E:
        R = E
    values = [int(n) for n in input().split()]
    answer = find_it(E, R, values)
    print('Case #{}: {}'.format(case+1, answer))
