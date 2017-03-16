import sys
from copy import deepcopy as copy

# fpIn = open("ex.in", "r")
# fpOut = open("ex.out", "w")
fpIn = open("small.in", "r")
fpOut = open("small.out", "w")
# fpIn = open("large.in", "r")
# fpOut = open("large.out", "w")

def raw_input():
    return fpIn.readline().strip()


class Print(object):
    def __init__(self, f):
        self.f = f

    def write(self, text):
        fpOut.write(text)
        self.f.write(text)

    def flush(self):
        fpOut.flush()
        self.f.flush()


class Map:
    def __init__(self, l, R, C):
        self.l = l
        self.R = R
        self.C = C

    def get(self, x, y):
        return self.l[x+(y*self.C)]

    def set(self, x, y, v):
        self.l[x+(y*self.C)] = v

    def get_adj(self, x, y):
        l = [(-1, -1), (-1, 0), (0, -1), (1, 0), (0, 1), (1, 1), (1, -1), (-1, 1)]
        a = []
        for i in l:
            nx = x+i[0]
            ny = y+i[1]
            if 0 <= nx < self.C and 0 <= ny < self.R:
                a.append((nx, ny))
        return a

    def lay_blank(self, x, y):
        self.set(x, y, 0)
        for a in self.get_adj(x, y):
            self.set(a[0], a[1], 0)

    def num_open(self):
        return self.l.count(0)


class Node:
    def __init__(self, m, x, y):
        """
        :type m: Map
        """
        self.m = m
        self.x = x
        self.y = y
        if self.m.get(x, y) != 0:
            raise Exception("You can not expand on closed cell")

    def search(self, O):
        if O == self.m.num_open():
            return self.m
        elif O < self.m.num_open():
            return None
        else:
            for a in self.m.get_adj(self.x, self.y):
                nm = copy(self.m)
                nm.lay_blank(a[0], a[1])
                if nm.num_open() <= O and nm.num_open() != self.m.num_open():
                    n = Node(nm, a[0], a[1])
                    m = n.search(O)
                    if m:
                        return m
                    del n, m


def do_test():
    line = raw_input().split()
    R = int(line[0])
    C = int(line[1])
    M = int(line[2])
    O = (R*C)-M

    t = [1]*(R*C)

    if O == 0:
        return "\nImpossible"

    if O == 1:
        m = Map(copy(t), R, C)
        m.l[0] = 0
        s = ""
        for ny in range(R):
            s += "\n"
            for nx in range(C):
                if nx == 0 and ny == 0:
                    s += "c"
                elif m.get(nx, ny) == 0 or m.get(nx, ny) == 2:
                    s += "."
                else:
                    s += "*"
        return s

    for sy in range((R/2)+1):
        for sx in range((C/2)+1):
            m = Map(copy(t), R, C)
            m.lay_blank(sx, sy)
            n = Node(m, sx, sy)
            m = n.search(O)

            if m:
                s = ""
                for ny in range(R):
                    s += "\n"
                    for nx in range(C):
                        if nx == sx and ny == sy:
                            s += "c"
                        elif m.get(nx, ny) == 0 or m.get(nx, ny) == 2:
                            s += "."
                        else:
                            s += "*"
                return s

    return "\nImpossible"


def main():
    line = raw_input()
    num_tests = int(line)
    for i in range(num_tests):
        print "Case #" + str(i+1) + ": " + do_test()

if __name__ == '__main__':
    if not isinstance(sys.stdout, Print):
        sys.stdout = Print(sys.stdout)
    main()

