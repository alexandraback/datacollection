import math, numpy, sys, functools


class memoized(object):
    def __init__(self, func):
        self._func = func
        self._cache = dict()

    def __call__(self, *args):
        try:
            return self._cache[args]
        except KeyError:
            result = self._func(*args)
            self._cache[args] = result
            return result

    def __get__(self, slf, _):
        return functools.partial(self.__call__, slf)




def solve_case(N, C):
    ancestors = dict()
    is_ancestor = set()
    for c, parents in C.items():
        is_ancestor.update(parents)
    no_children = set(range(1, N + 1))
    no_children.difference_update(is_ancestor)

    def get_ancestors_of(i):
        if i in ancestors:
            return ancestors[i]
        s = set()
        for p in C[i]:
            s.add(p)
            s.update(get_ancestors_of(p))
        ancestors[i] = s
        return s

    visited = set()

    for c in range(1, N + 1):
        visited = set()
        for p in C[c]:
            if p in visited:
                return 'Yes'
            visited.add(p)
            a = get_ancestors_of(p)
            if visited.intersection(a):
                return 'Yes'
            visited.update(a)
    return 'No'

def read_case(instream):
    N = int(instream.readline().strip())
    C = dict()
    for c in range(1, N + 1):
        line = [int(i) for i in instream.readline().strip().split()]
        M = line[0]
        inherits = line[1:]
        assert len(inherits) == M
        C[c] = inherits
    return N, C


def do_cases(instream):
    T = int(instream.readline())
    for t in range(1, T + 1):
        case_params = read_case(instream)
        result = solve_case(*case_params)
        print('Case #%d: %s' % (t, result))
        t += 1


if __name__ == '__main__':
    #    do_cases(open('test.in', 'r'))
    do_cases(sys.stdin)

