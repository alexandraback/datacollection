def check_impossible(keys, opens, chests, curr_indexes):
    total_keys = {k:v for k,v in keys.iteritems()}
    c_opens = [o for i, o in enumerate(opens) if curr_indexes[i]]
    c_chests = [c for i, c in enumerate(chests) if curr_indexes[i]]
    l = len(c_chests)

    for c_chest in c_chests:
        for key in c_chest:
            if key in total_keys:
                total_keys[key] += 1
            else:
                total_keys[key] = 1

    for i in xrange(l):
        for k in c_chests[i]:
            total_keys[k] -= 1
        if c_opens[i] not in total_keys or total_keys[c_opens[i]] == 0:
            return True
        for k in c_chests[i]:
            total_keys[k] += 1

    for c_open in c_opens:
        total_keys[c_open] -= 1
        if total_keys[c_open] == -1:
            return True

    binary_keys = {k:(v != 0) for k,v in keys.iteritems()}
    pairs = zip(c_opens, c_chests)
    while True:
        if not pairs:
            break
        next_pairs = []
        for pair in pairs:
            o, chest = pair
            if binary_keys[o]:
                for k in chest:
                    binary_keys[k] = True
            else:
                next_pairs.append(pair)
        if len(pairs) == len(next_pairs):
            return True
        pairs = next_pairs

    return False

def dict_to_tuple(dictionary):
    return tuple([(k,dictionary[k]) for k in sorted(dictionary.keys())])

def calc_state(keys, curr_indexes):
    return (dict_to_tuple(keys), tuple(curr_indexes))

def pop_up(keys, opens, chests, curr_indexes, index):
    keys[opens[index]] += 1
    for k in chests[index]:
        keys[k] -= 1
    curr_indexes[index] = True

def push_down(keys, opens, chests, curr_indexes, index):
    keys[opens[index]] -= 1
    for k in chests[index]:
        keys[k] += 1
    curr_indexes[index] = False

def try_new(keys, opens, chests, curr_indexes, start_index, baddies):
    while start_index < len(chests):
        if curr_indexes[start_index] and keys[opens[start_index]] != 0:
            push_down(keys, opens, chests, curr_indexes, start_index)
            return start_index
        start_index += 1

    baddies.add(calc_state(keys, curr_indexes))
    return -1


def solve(N, keys, opens, chests):
    baddies = set()
    curr_indexes = [True for _ in xrange(N)]
    stack = [-1]

    while True:
        if len(stack) == N + 1:
            return ' '.join(map(lambda x: str(x + 1), stack[1:]))

        if check_impossible(keys, opens, chests, curr_indexes) or calc_state(keys, curr_indexes) in baddies:
            baddies.add(calc_state(keys, curr_indexes))
            last = stack.pop()
            if last == -1:
                break
            pop_up(keys, opens, chests, curr_indexes, last)
            start_index = last + 1
        else:
            start_index = 0

        new_index = try_new(keys, opens, chests, curr_indexes, start_index, baddies)
        if new_index != -1:
            stack.append(new_index)

    return "IMPOSSIBLE"

T = int(raw_input().strip())
for i in xrange(T):
    K, N = map(int, raw_input().strip().split(' '))
    tmp_keys = map(int, raw_input().strip().split(' '))
    keys = {i:0 for i in xrange(201)}
    for tkey in tmp_keys:
        keys[tkey] += 1
    opens = [0 for _ in xrange(N)]
    chests = [[] for _ in xrange(N)]
    for j in xrange(N):
        tmp = map(int, raw_input().strip().split(' '))
        opens[j] = tmp[0]
        if tmp[1] != 0:
            chests[j] = tmp[2:]
    print "Case #%s: %s" % (i + 1, solve(N, keys, opens, chests))