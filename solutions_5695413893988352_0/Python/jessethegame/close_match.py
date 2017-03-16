from itertools import chain

file = 'B-small-attempt1.in'

def brute_force_close_match(C, J):
    if not len(C):
        yield [], []
    else:
        c = C[0]
        j = J[0]
        if (c, j) == ('?', '?'):
            for _c in (0, 9):
                for _j in (0, 9):
                    for _C, _J in brute_force_close_match(C[1:], J[1:]):
                        yield chain([_c], _C), chain([_j], _J)
        elif c == '?':
            j = int(j)
            for _c in set((0, max(j - 1, 0), j, min(j + 1, 9), 9)):
                for _C, _J in brute_force_close_match(C[1:], J[1:]):
                    yield chain([_c], _C), chain([j], _J)
        elif j == '?':
            c = int(c)
            for _j in set((0, max(c - 1, 0), c, min(c + 1, 9), 9)):
                for _C, _J in brute_force_close_match(C[1:], J[1:]):
                    yield chain([c], _C), chain([_j], _J)
        else:
            c = int(c)
            j = int(j)
            for _C, _J in brute_force_close_match(C[1:], J[1:]):
                yield chain([c], _C), chain([j], _J)

def close_match_rows(C, J):
    for c, j in brute_force_close_match(C, J):
        c = ''.join(map(str, c))
        j = ''.join(map(str, j))
        yield (abs(int(c) - int(j)), c, j)

def close_match(C, J):
    (diff, c, j) = min(close_match_rows(C, J))
    return c, j

with open(file) as handle:
  T = int(handle.readline())

  for t in range(T):
    C, J = handle.readline().strip().split(' ')

    print "Case #{}: {} {}".format(t + 1, *close_match(C, J))
