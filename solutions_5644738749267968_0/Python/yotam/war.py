#!/usr/bin/env python
import sys
import bisect

fin = sys.stdin
fout = sys.stdout
ferr = sys.stderr

def ew(s):
    sys.stderr.write("%s\n" % s)

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

def get_reals():
    line = fin.readline()
    return map(float, line.split())

def get_line():
    line = fin.readline()
    if len(line) > 0 and line[-1] == '\n':
        line = line[:-1]
    return line

def get_string():
    line = fin.readline()
    return line.strip()

def war():
    N = get_number()
    naomi_deck = get_reals()
    ken_deck = get_reals()
    naomi_deck.sort()
    ken_deck.sort()

    
    # Deciteful
    naomi = naomi_deck[:]
    ken = ken_deck[:]
    y = 0
    i = 0
    while len(ken) > 0:
        if naomi[i] > ken[0]:
            y += 1 # Naomi tells she has 0.99999 so Ken deals his minimal
            ken.pop(0)
        else:
            ken.pop(-1) # Naomi tells she has something just below Ken's max
        i += 1


    # Honest
    naomi = naomi_deck[:]
    ken = ken_deck[:]
    z = 0
    i = 0
    while i < N:
        naomi_card = naomi.pop(0)
        bi = bisect.bisect_left(ken, naomi_card)
        if bi < len(ken):
            ken.pop(bi) # Ken wins
        else:
            ken.pop(0) # Naomi wins
            z += 1
        i += 1

    return "%d %d" % (y, z)
       

if __name__ == "__main__":
    (fin, fout) = get_io(sys.argv)
    n_cases = get_number()
    for ci in range(n_cases):
        r = war()
        fout.write("Case #%d: %s\n" % (ci + 1, r))

    fin.close()
    fout.close()
    sys.exit(0)
