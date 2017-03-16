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

    def find_kernels(self):
        global consonants
        self.kernels = []
        sz = len(self.name)
        i = 0
        nccc = 0 # Number of consecutive current consonants
        cb = ce = -1
        while i < sz:
            c = self.name[i]
            if c in consonants:
                if nccc == 0:
                    cb = i
                nccc += 1
            else:
                if nccc >= self.n:
                    ce = i
                    self.kernels.append((cb, ce))
                nccc = 0
            i += 1
        if nccc >= self.n:
            ce = i
            self.kernels.append((cb, ce))
        # self.log("kernels=%s" % self.kernels)
        

    def solve(self):
        self.nval = 0
        self.find_kernels()
        nk = len(self.kernels)
        ki = 0
        b = 0
        e = len(self.name)
        while ki < nk:
            # Find how many n-val substring thanks to kernels[ki],
            # but _not_ preceding kernels ( kernels[ji]  for ji < ki ).
            if ki > 0:
                b = self.kernels[ki - 1][1] - self.n + 1
            # so we need to find substring in within [b,e)
            # that have at least  n  from  kernels[ki]
            kb = self.kernels[ki][0]
            ke = self.kernels[ki][1]
            #  b <= kb < ke <= e
            self.log0("ki=%d, b=%d, kb=%d, ke=%d, e=%d" %
                     (ki, b, kb, ke, e))
            n_whole = (kb - b + 1)*(e - ke + 1)
            # how many ends in x within [kb, ke-1)
            # Wed must have x - kb >= n,  so ...
            #   x - n - b + 1
            # We need to sum  x= kb+n till ke - 1
            n_ends = 0
            xlow = kb + self.n
            xhigh = ke - 1
            nx = xhigh - xlow + 1
            if nx > 0:
                a_first = xlow - self.n - b + 1
                a_last = xhigh - self.n - b + 1
                n_ends = ((a_first + a_last)*nx)/2
            # how many starts in x within [kb + 1, ke-n)
            # Wed must have ke - x  >= n,  so ...
            #   e - (x + n) + 1
            # We need to sum  x= kb+1 till ke - n
            n_starts = 0
            xlow = kb + 1
            xhigh = ke - self.n
            nx = xhigh - xlow + 1
            if nx > 0:
                a_first = e - (xlow + self.n) + 1
                a_last = e - (xhigh + self.n) + 1
                n_starts = ((a_first + a_last)*nx)/2
            # We counted 'real' substrings of the kernel twice
            # g-sized such are  (ke - kb) - g + 1
            n_subkernel = 0
            g_low = self.n
            g_high = ke - kb - 1
            ng = g_high - g_low
            if ng > 0:
                a_first = (ke - kb) - g_low + 1
                a_last = (ke - kb) - g_high + 1
                n_subkernel = ((a_first + a_last)*ng)/2
            self.log0("ki=%d, whole=%d, ends=%d, starts=%d, subkernel=%d" %
                     (ki, n_whole, n_ends, n_starts, n_subkernel))
            k_add = n_whole + n_ends + n_starts - n_subkernel
            # self.log("ki=%d, k_add=%d" % (ki, k_add))
            self.nval += k_add
            ki += 1
            
            
            

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
        # c.solve_naive()
        c.solve()
        fout.write("Case #%d: %s\n" % (ci + 1, c.nval))

    fin.close()
    fout.close()
    sys.exit(0)
