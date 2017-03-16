## This is a polyomino problem
## http://en.wikipedia.org/wiki/Polyomino

import sys

def is_filling_grid(x, r, c):
    if x >= 7:
        # A hole exists for x >= 7, which cannot be filled 
        return False
    elif r % x != 0 and c % x != 0:
        # http://en.wikipedia.org/wiki/Packing_problems#Related_fields
        # An r × c rectangle can be packed with 1 × x strips iff x divides r or x divides c
        return False
    elif x == 3 and r * c < 3*2:
        return False
    elif x == 4 and r * c < 4*3:
        return False
    elif x == 5 and r * c < 5*4:
        return False
    elif x == 6 and r * c < 6*5:
        return False
    else:
        return True
    
def parse(ss):
    n, rest = int(ss[0]), ss[1:]
    return [[int(s) for s in line.split()] for line in rest]

def bool_to_name(tf):
    return "GABRIEL" if tf else "RICHARD"

if __name__ == '__main__':
    with open(sys.argv[1], "r") as f:
        xrc_list = parse([line for line in f if line.rstrip()])
    
    for (i, xrc) in enumerate(xrc_list):
        s = bool_to_name(is_filling_grid(*xrc))
        print("Case #%d: %s" % (i + 1, s))
