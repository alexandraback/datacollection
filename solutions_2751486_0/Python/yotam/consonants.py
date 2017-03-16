#!/usr/bin/env python
import sys

fin = sys.stdin
fout = sys.stdout
ferr = sys.stderr

def get_io(argv):
    fin = sys.stdin
    fout = sys.stdout
    ifn = ofn = "-"
    if len(argv) == 2:
        bfn = sys.argv[1]
        ifn = bfn + '.in'
        ofn = bfn + '.out'
    if len(argv) > 2:
        ifn = argv[1]
        ofn = argv[2]
    if ifn != '-':
        fin = open(ifn, "r")
    if ofn != '-':
        fout = open(ofn, "w")
    return (fin, fout)

def get_numbers():
    line = fin.readline()
    return map(int, line.split())

def get_number():
    return get_numbers()[0]

def get_line():
    line = fin.readline()
    if len(line) > 0 and line[-1] == '\n':
        line = line[:-1]
    return line

def get_string():
    line = fin.readline()
    return line.strip()

consonants = set()
for c in "bcdfghjklmnpqrstvwxyz":
    consonants.add(c)
sys.stderr.write("#consonants=%d\n" % len(consonants))

class Consonants:
    def __init__(self, name, n):
        self.name = name
        self.n = n

    def solve_naive(self):
        global consonants
        self.nval = 0
        sz = len(self.name)
        i_end = sz - self.n + 1
        j_end = sz + 1
        i = 0
        while i < i_end:
            j = i + self.n
            while j < j_end:
                nc = 0
                k = i
                while k < j and nc < self.n:
                    c = self.name[k]
                    if c in consonants:
                        nc += 1
                    else:
                        nc = 0
                    k += 1
                if nc >= self.n:
                    self.log0("[%d] i=%d, j=%d, s=%s" % 
                             (self.nval, i, j, self.name[i:j]))
                    self.nval += 1
                j += 1
            i += 1
       
    def log(self, msg):
        sys.stderr.write("%s\n" % msg)

    def log0(self, msg):
        pass

if __name__ == "__main__":
    (fin, fout) = get_io(sys.argv)
    n_cases = get_number()
    for ci in range(n_cases):
        line = get_line()
        ss = line.split()
        c = Consonants(ss[0], int(ss[1]))
        c.solve_naive()
        # c.solve()
        fout.write("Case #%d: %s\n" % (ci + 1, c.nval))

    fin.close()
    fout.close()
    sys.exit(0)
