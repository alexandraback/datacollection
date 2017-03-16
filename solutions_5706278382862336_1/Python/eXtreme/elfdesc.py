def solve_elf_family(P, Q):
    if P == 0:
        return 100

    if P > Q:
        raise ValueError()

    if P == Q:
        return 0

    P *= 2
    if P > Q:
        return 1 + min(solve_elf_family(Q, Q), solve_elf_family(P-Q, Q))
    else:
        return 1 + min(solve_elf_family(0, Q), solve_elf_family(P, Q))

def answer(P, Q):
    try:
        n = solve_elf_family(P, Q)
    except ValueError:
        return 'impossible'
    except RuntimeError:
        return 'impossible'

    if n > 40:
        return 'impossible'

    return str(n)


import sys
infname = sys.argv[1]
with open(infname) as inf:
    with open(infname.replace('.in', '.out'), 'w') as outf:
        T = int(inf.readline())
        for t in range(1, T+1):
            P, Q = map(int, inf.readline().split('/'))
            outf.write('Case #{}: {}\n'.format(t,answer(P, Q)))
