import sys

chest_info = [None for _ in xrange(200)]
failures = {}

def populate_chest_info(chests):
    for i, chest in enumerate(chests):
        chest_info[i] = chest


def make_key_list(keys, max):
    kl = [0 for _ in xrange(max)]
    for key in keys:
        kl[key - 1] += 1
    return kl


def try_unlock_chest(keys, chest_i):
    chest = chest_info[chest_i]
    key_needed = chest[0]

    if keys[key_needed - 1]:
        keys[key_needed - 1] -= 1

        for i in xrange(2, len(chest)):
            if chest[i] > 0:
                try:
                    keys[chest[i] - 1] += 1
                except IndexError, e:
                    pass

        return True
    return False


def make_move(moves, chests, chest, i):
    moves[i] = chest
    chests[chest - 1] = 0


def unmake_move(moves, chests, chest, i):
    moves[i] = 0
    chests[chest - 1] = chest


def relock_chest(keys, chest_i):
    chest = chest_info[chest_i]
    key_needed = chest[0]
    keys[key_needed - 1] += 1

    for i in xrange(2, len(chest)):
        if chest[i] > 0:
            try:
                keys[chest[i] - 1] -= 1
            except IndexError, e:
                pass


def know_will_fail(keys, chests):
    k = str(chests)
    prev = failures.get(k)

    if prev:
        for i in xrange(len(prev)):
            if prev[i] < keys[i]:
                return False
        return True

    return False


def register_failure(keys, chests):
    k = str(chests)
    prev = failures.get(k)
    if prev is None or sum(keys) > sum(prev):
        failures[k] = keys[:]


def solve_case_rec(keys, chests, moves, i):
    if i == len(moves):
        return moves

    if know_will_fail(keys, chests):
        return False

    for chest in chests:
        if chest > 0:
            if try_unlock_chest(keys, chest - 1):
                make_move(moves, chests, chest, i)

                solved = solve_case_rec(keys, chests, moves, i + 1)
                if solved:
                    return solved

                # undo modifications
                unmake_move(moves, chests, chest, i)
                relock_chest(keys, chest - 1)

    register_failure(keys, chests)
    return False


def solve_case(keys, chests, moves):
    return solve_case_rec(keys, chests, moves, 0)


def solve(input):
    cases, = input.pop(0)
    for i in xrange(cases):
        chests = []
        _, num_chests = input.pop(0)

        keys = input.pop(0)
        all_keys = keys[:]

        for j in xrange(num_chests):
            chest = input.pop(0)
            chest_info[j] = chest
            all_keys.append(chest[0])
            chests.append(chest)

        global failures
        failures = {}
        solution = solve_case(make_key_list(keys, max(all_keys)),
                              range(1, num_chests+1),
                              [0 for _ in xrange(num_chests)])

        for j in xrange(num_chests):
            chest_info[j] = None

        print "Case #{0}: {1}".format(i+1, ' '.join(map(str, solution)) if solution else "IMPOSSIBLE")

input = map(lambda x: map(int, x.split(' ')), sys.stdin.read().strip().split('\n'))
solve(input)