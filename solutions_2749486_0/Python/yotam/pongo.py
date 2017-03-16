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

class Pongo:
    def __init__(self, x, y):
        self.x = x
        self.y = y

    def solve_naive(self):
        self.r = ""
        jump = 1
        s = 0

        while s < self.x:
            self.r += "WE"
            s += 1
        while s > self.x:
            self.r += "EW"
            s -= 1

        s = 0
        while s < self.y:
            self.r += "SN"
            s += 1
        while s > self.y:
            self.r += "NS"
            s -= 1
            

if __name__ == "__main__":
    (fin, fout) = get_io(sys.argv)
    n_cases = get_number()
    for ci in range(n_cases):
        xy = get_numbers()
        pongo = Pongo(xy[0], xy[1])
        pongo.solve_naive()
        fout.write("Case #%d: %s\n" % (ci + 1, pongo.r))

    fin.close()
    fout.close()
    sys.exit(0)
