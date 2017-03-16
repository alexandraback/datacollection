#!/usr/bin/env python
# -*- coding: utf-8 -*=

def solve():
    global G
    code = IN().strip()
    plain = code.translate(G)
    G.update(str.maketrans(code, plain))
    return plain

if __name__ == '__main__':
    G = {32: 32,
 97: 121,
 98: 104,
 99: 101,
 100: 115,
 101: 111,
 102: 99,
 103: 118,
 104: 120,
 105: 100,
 106: 117,
 107: 105,
 108: 103,
 109: 108,
 110: 98,
 111: 107,
 112: 114,
 113: 122,
 114: 116,
 115: 110,
 116: 119,
 117: 106,
 118: 112,
 119: 102,
 120: 109,
 121: 97,
 122: 113}
    OUT = open('A-small-attempt3.out','w')
    IN = open('A-small-attempt3.in').__next__
    T = range(1, int(IN())+1)
    for case in T:
        result = solve()
        print("Case #{}: {}".format(case, result), file=OUT)
        print("Case #{}: {}".format(case, result))
