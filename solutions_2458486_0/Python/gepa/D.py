import sys


_K = 0
_N = 0
_types = []
_buf = []
_keys_in_chest = []


def can_open(b, current_keys):
    if _buf[b] is not None:
        return _buf[b]
    q = b
    i = 0
    res = True
    while q > 0:
        if q % 2 == 0:
            q /= 2
            i += 1
            continue
        res = False
        if current_keys[_types[i]] > 0:
            current_keys[_types[i]] -= 1
            for j in xrange(len(_keys_in_chest[i])):
                current_keys[_keys_in_chest[i][j]] += 1
            p = can_open(b ^ (1 << i), current_keys)
            current_keys[_types[i]] += 1
            for j in xrange(len(_keys_in_chest[i])):
                current_keys[_keys_in_chest[i][j]] -= 1
            if p:
                _buf[b] = True
                return True
        q /= 2
        i += 1
    _buf[b] = res
    return res


def how_to_open(b, current_keys):
    if not can_open(b, current_keys):
        return "IMPOSSIBLE"
    q = b
    i = 0
    while q > 0:
        if q % 2 == 1 and current_keys[_types[i]] > 0:
            current_keys[_types[i]] -= 1
            for j in xrange(len(_keys_in_chest[i])):
                current_keys[_keys_in_chest[i][j]] += 1
            p = can_open(b ^ (1 << i), current_keys)
            if p:
                return "%d %s" % (i + 1, how_to_open(b ^ (1 << i), current_keys))
            current_keys[_types[i]] += 1
            for j in xrange(len(_keys_in_chest[i])):
                current_keys[_keys_in_chest[i][j]] -= 1
        q /= 2
        i += 1
    return ""


def compute(K, N, types, keys_in_chest, key_counts):
    global _K, _N, _types, _keys_in_chest, _buf
    _K = K
    _N = N
    _types = types
    _keys_in_chest = keys_in_chest
    _buf = [None] * 2000000
    return how_to_open((1 << N) - 1, key_counts)


def parse():
    K, N = map(int, sys.stdin.readline().strip().split())
    types = []
    keys_in_chest = []
    key_counts = [0] * 201
    keys = map(int, sys.stdin.readline().strip().split())
    for k in keys:
        key_counts[k] += 1
    for i in xrange(N):
        tmp = map(int, sys.stdin.readline().strip().split())
        types.append(tmp[0])
        keys_in_chest.append(tmp[2:])
    return K, N, types, keys_in_chest, key_counts


if __name__ == "__main__":
    sys.setrecursionlimit(100000)
    T = int(sys.stdin.readline().strip())
    count = 1
    part = 0
    if len(sys.argv) == 3:
        part = int(sys.argv[1])
        count = int(sys.argv[2])
    for i in xrange(T):
        data = parse()
        if i * count >= part * T and i * count < (part + 1) * T:
            result = compute(*data)
            print "Case #%d: %s" % (i + 1, result)
