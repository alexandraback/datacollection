#!/usr/bin/python

read_int = lambda: int(raw_input())
read_lint = lambda: map(int, raw_input().split())

mapping = {
    ('i', 'i'): (-1, -1),
    ('i', 'j'): (1, 'k'),
    ('i', 'k'): (-1, 'j'),
    ('j', 'i'): (-1, 'k'),
    ('j', 'j'): (-1, -1),
    ('j', 'k'): (1, 'i'),
    ('k', 'i'): (1, 'j'),
    ('k', 'j'): (-1, 'i'),
    ('k', 'k'): (-1, -1),
}

def multiply(state, ch):
    if state[1] == -1:
        return (-1, ch)
    if state[1] == 1:
        return (state[0], ch)
    ns = mapping[(state[1], ch)]
    if ns[1] == -1:
        return ns[0] * state[0], ns[1] * state[0]
    return (ns[0] * state[0], ns[1])

def to_state(goal, state, it):
    while state != goal:
        nch = next(it, None)
        if nch is None:
            return False
        state = multiply(state, nch)
    return True


def solver(it):
    for gc in 'ijk':
        nc = next(it, None)
        if nc is None or not to_state((1, gc), (1, nc), it):
            return 'NO'
    nc = next(it, None)
    if nc is None:
        return 'YES'
    state = (1, nc)
    for nc in it:
        state = multiply(state, nc)
    return 'YES' if state == (1, 1) else 'NO'


def solve_case(numc):
    L, X = read_lint()
    ijk = X * raw_input().strip()
    it = iter(ijk)

    print "Case #{}:".format(numc), solver(it)


def main():
    for i in xrange(1, read_int() + 1):
        solve_case(i)


if __name__ == '__main__':
    main()