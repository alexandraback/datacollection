
def handle(E, R, N, vs):

    states = [(E, 0)]
    curr_max = 0

    for i, v in enumerate(vs):

        new_states = []

        for curr_e, curr_gain in states:

            for e in xrange(curr_e + 1):
                new_e = curr_e - e + R
                if new_e > E:
                    new_e = E
                new_gain = curr_gain + e * v
                if new_gain > curr_max:
                    curr_max = new_gain
                new_states.append((new_e, new_gain))


        at_best = E * sum(vs[i+1:])

        states = new_states
        new_states = []
        for some_e, some_gain in states:
            if not (some_gain + at_best < curr_max):
                new_states.append((some_e, some_gain))

        states = new_states


    max_gain = 0
    for e, gain in states:
        if gain > max_gain:
            max_gain = gain

    return max_gain

for case in xrange(int(raw_input())):
    parts = [int(x) for x in raw_input().split()]
    E = parts[0]
    R = parts[1]
    N = parts[2]
    vs = [int(x) for x in raw_input().split()]
    print 'Case #%d: %s' % (case + 1, handle(E, R, N, vs))

