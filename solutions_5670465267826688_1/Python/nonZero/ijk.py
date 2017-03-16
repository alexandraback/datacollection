import logging
import time

logging.basicConfig(level=logging.DEBUG)
logger = logging.getLogger(__name__)

IJK = {
    'ij': '+k',
    'ik': '-j',

    'ji': '-k',
    'jk': '+i',

    'ki': '+j',
    'kj': '-i',
}


def calc(a, b):
    """ a, b and return value are strings of length 2:

    >>> calc("+i", "+j")
    '+k'

    >>> calc("-i", "-j")
    '+k'

    >>> calc("-i", "+j")
    '-k'

    >>> calc("+i", "-j")
    '-k'

    >>> calc("+i", "+i")
    '-1'

    >>> calc("+i", "-i")
    '+1'

    >>> calc("-i", "-i")
    '-1'

    >>> calc("+1", "-i")
    '-i'

    >>> calc("+i", "-1")
    '-i'

    >>> calc("+i", "-1")
    '-i'


    """
    sign = "-" if a[0] != b[0] else "+"
    if a[1] == "1":
        return sign + b[1]
    if b[1] == "1":
        return sign + a[1]
    if a[1] == b[1]:
        return ("-" if sign == "+" else "+") + "1"
    negative, char = IJK[a[1] + b[1]]
    return ("+" if negative == sign else "-") + char


def solve(s, x):
    """
    >>> solve("ik", 1)
    False

    >>> solve("ijk", 3)
    True

    >>> solve("kji", 1)
    False

    >>> solve("ji", 6)
    True

    >>> solve("i", 10000)
    False
    """
    states = {}

    expected = [
        "+i",  # "i"
        "+k",  # "j"
    ]
    state = "+1"
    i = 0
    while i < x:
        do_not_cache = False
        start = state
        for c in s:
            state = calc(state, "+" + c)
            if expected and expected[0] == state:
                del expected[0]
                do_not_cache = True
        end = state
        i += 1
        if do_not_cache:
            states = {}
        else:
            states[start] = end
            if end in states:
                # loop detected, can skip many iterations.
                n = 0
                node = start
                while True:
                    n += 1
                    node = states[node]
                    if node == start:
                        left = x - i
                        loops = left // n
                        i += loops * n
                        logger.debug("skipped %d", loops * n)
                        break

    if expected:
        return False
    return state == "-1"


if __name__ == "__main__":
    t0 = time.time()
    T = int(input())
    for i in range(T):
        X = int(input().split()[-1])
        L = input()
        print("Case #{}: {}".format(i + 1, "YES" if solve(L, X) else "NO"))
    logger.debug("done in %0.4f seconds.", time.time() - t0)
