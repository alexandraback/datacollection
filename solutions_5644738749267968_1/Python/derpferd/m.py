import sys
from copy import deepcopy as copy

# fpIn = open("ex.in", "r")
# fpOut = open("ex.out", "w")
# fpIn = open("small.in", "r")
# fpOut = open("small.out", "w")
fpIn = open("large.in", "r")
fpOut = open("large.out", "w")


def raw_input():
    return fpIn.readline().strip()


class Print(object):
    def __init__(self, f):
        self.f = f

    def write(self, text):
        fpOut.write(text)
        self.f.write(text)


def get_bigger_closest(n, l):
    l.sort()
    for x in l:
        if x > n:
            return x
    return 0.0

def play_d_war(n, k):
    points = 0
    while n:
        if min(k) < max(n):
            points += 1
            n.pop(n.index(get_bigger_closest(min(k), n)))
            k.pop(k.index(min(k)))
        else:
            n.pop(n.index(min(n)))
            k.pop(k.index(max(k)))

    return points


def play_war(n, k):
    points = 0
    while n:
        if max(k) < max(n):
            points += 1
            n.pop(n.index(max(n)))
            k.pop(k.index(min(k)))
        else:
            k.pop(k.index(get_bigger_closest(max(n), k)))
            n.pop(n.index(max(n)))

    return points


def do_test():
    line = raw_input().split()
    blocks = int(line[0])
    n = [float(x) for x in raw_input().split()]
    k = [float(x) for x in raw_input().split()]

    return str(play_d_war(copy(n), copy(k))) + " " + str(play_war(copy(n), copy(k)))

def main():
    line = raw_input()
    num_tests = int(line)
    for i in range(num_tests):
        print "Case #" + str(i+1) + ": " + do_test()

if __name__ == '__main__':
    if not isinstance(sys.stdout, Print):
        sys.stdout = Print(sys.stdout)
    main()

