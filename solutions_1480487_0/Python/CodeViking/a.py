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


def solve_case(N, J):
    X = float(sum(J))
    A = [[1.0 if j == 0 else (-1 if j == i else 0.0)for j in range(N)] for i in range(1, N)]
    A.append([1.0] * N)
    A = numpy.array(A)
    b = [(J[i] - J[0]) / X for i in range(1, N)]
    b.append(1.0)
    b = numpy.array(b).transpose()
    x = 100.0 * numpy.linalg.solve(A, b)

    result = ' '.join([str(i) for i in x])
    return result


def read_case(instream):
    ints = [int(ns) for ns in instream.readline().strip().split()]
    N = ints[0]
    J = ints[1:]
    return N, J


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

