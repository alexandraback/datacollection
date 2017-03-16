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
            return False, state
        state = multiply(state, nch)
    return True, None

def find_all(states, stages, reps, from_state=None):
    cur_state = from_state
    goal_state = next(states)
    for repits in xrange(reps):
        for pos in xrange(len(stages)):
            cur_state = multiply(cur_state, stages[pos]) if cur_state else (1, stages[pos])
            if cur_state == goal_state:
                cur_state = None
                goal_state = next(states, None)
                if not goal_state:
                    return True, pos, repits
    return False, 0, 0

def solver(ijk, X):
    states = ((1, 'i'), (1, 'j'), (1, 'k'))
    found, lpos, reps = find_all(iter(states), ijk, min(X, 15))
    if not found:
        return 'NO'

    X -= reps + 1

    state = (1, ijk[lpos+1]) if (lpos + 1) < len(ijk) else None
    for pos in xrange(lpos + 2, len(ijk)):
        state = multiply(state, ijk[pos])

    if X == 0:
        return 'YES' if (state == (1, 1) or state is None) else 'NO'

    mod = X % 4
    line_state = (1, 1)
    for _ in xrange(mod):
        for pos in xrange(len(ijk)):
            line_state = multiply(line_state, ijk[pos])

    if state:
        if state[1] == -1:
            return 'YES' if line_state[1] == -1 else 'NO'
        if state[1] == 1:
            return 'YES' if line_state[1] == 1 else 'NO'
        return 'YES' if (state[0] == -line_state[0] and state[1] == line_state[1]) else 'NO'
    return 'YES' if line_state == (1, 1) else 'NO'


def solve_case(numc):
    L, X = read_lint()
    ijk = raw_input().strip()

    print "Case #{}:".format(numc), solver(ijk, X)


def main():
    for i in xrange(1, read_int() + 1):
        solve_case(i)


if __name__ == '__main__':
    main()