__author__ = 'artiom'

from fractions import gcd

def is_power_of_two(x):
    while (x % 2 == 0 and x > 0):
        x /= 2
    if (x != 1):
        return False
    else:
        return True

def solve(p, q):
    if (not is_power_of_two(q)):
        return -1
    result = 1
    while p < q / 2:
        result += 1
        if (q % 2 != 0):
            return -1
        q /= 2
    return result


def read_input(filename="A.in"):
    f = open(filename)

    ncases = int(f.readline())

    for ncase in xrange(ncases):
        p,q = map(int, f.readline().split("/"))
        d = gcd(p, q)
        p /= d
        q /= d
        res = solve(p, q)
        if (res == -1):
            print "Case #" + str(ncase + 1) + ": " + "impossible"
        else:
            print "Case #" + str(ncase + 1) + ": " + str(res)

    f.close()


if __name__ == "__main__":
    read_input("A-large.in")