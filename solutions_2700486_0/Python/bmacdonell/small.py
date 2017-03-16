#!env python2

from collections import defaultdict
from copy import deepcopy
import sys


def state_key(state):
    return tuple(state.items())

def get_base_y(state, x):
    if x % 2 == 0:
        base = -2
    else:
        base = -1

    return state.get(x, base)


def get_y(last_state, x):
    left = get_base_y(last_state, x - 1)
    center = get_base_y(last_state, x)
    right = get_base_y(last_state, x + 1)
    return max(left, center, right) + 2


def build_states(last_state):
    results = []
    possibilities = [(1.0, 0)]

    # Determine where the diamond can land
    while len(possibilities) > 0:
        next_possibilities = []

        for probability, x in possibilities:
            y = get_base_y(last_state, x)
            left = get_base_y(last_state, x - 1)
            right = get_base_y(last_state, x + 1)

            if left < y and right > y:
                next_possibilities.append((probability, x - 1))
            elif left > y and right < y:
                next_possibilities.append((probability, x + 1))
            elif left < y and right < y:
                next_possibilities.append((probability / 2.0, x - 1))
                next_possibilities.append((probability / 2.0, x + 1))
            else:
                results.append((probability, x))

        possibilities = next_possibilities

    # Turn all of the results into states
    new_states = []
    for probability, x in results:
        new_state = deepcopy(last_state)
        new_state[x] = get_base_y(new_state, x) + 2
        new_states.append((probability, new_state))

    return new_states


def add_state(states, probability, state):
    k = state_key(state)
    if k in states:
        old_probability, _ = states[k]
        probability += old_probability

    states[k] = (probability, state)


def simulate(n):
    initial_state = {}
    states = {}
    states[state_key(initial_state)] = (1.0, initial_state)

    for i in range(n):
        next_states = {}
        for _, (probability, old_state) in states.items():
            for new_probability, new_state in build_states(old_state):
                add_state(next_states, probability * new_probability, new_state)
        states = next_states

    return states


def combine_states(states):
    min_x = min((min(s.keys()) for _, s in states))
    max_x = max((max(s.keys()) for _, s in states))
    probability_cdfs = {}

    for x in range(min_x, max_x + 1):
        probability_cdf = defaultdict(lambda: 0)
        for (p, s) in states:
            y = get_base_y(s, x)
            for a_y in range(y + 1):
                probability_cdf[a_y] += p
        probability_cdfs[x] = probability_cdf

    return probability_cdfs


def test_cdf(cdfs, x, y):
    return cdfs[x][y]


def read_ints(line):
    return map(int, line.strip().split(' '))


def read_input():
    count = int(sys.stdin.readline().strip())

    for _ in range(count):
        n, x, y = read_ints(sys.stdin.readline())
        yield n, x, y


case = 1
for n, x, y in read_input():
    states = simulate(n)
    cdfs = combine_states(states.values())
    if not x in cdfs or not y in cdfs[x]:
        result = 0
    else:
        result = cdfs[x][y]
    print "Case #%d: %s" % (case, result)
    case += 1
