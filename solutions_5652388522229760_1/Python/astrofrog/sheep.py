# Author: Thomas P. Robitaille
# Executed using Python 3

from collections import Counter


def find_sleep_number(start):
    """
    Given a starting value 'start', find the last number that Bleatrix will
    name before falling asleep
    """
    # In the range 0 to 10^6, only the value 0 results
    # in insomnia:
    if start == 0:
        return 'INSOMNIA'
    c = Counter()
    for i in range(1, 10000000):
        c.update(str(start * i))
        if len(c) == 10:
            break
    return i * start


with open('A-large.in', 'r') as f:
    t = int(f.readline())
    for i in range(t):
        n = int(f.readline())
        print("Case #{0}: {1}".format(i + 1, find_sleep_number(n)))
