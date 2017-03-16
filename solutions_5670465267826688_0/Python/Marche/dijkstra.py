#!/usr/bin/python3

import sys
from functools import reduce

DEBUG = False

def debug(s):
    if DEBUG:
        print(s)
    else:
        pass

def quater(x, y):
    """ Quaternion multiplication.
        possible values for x and y:
        'i', 'j', 'k', 'o'
        'I', 'J', 'K', 'O'
        ('o' means 'one'; the second line represents the negatives)
    """
    order = 'ijki'
    if x == 'o':
        return y
    elif y == 'o':
        return x
    elif x == 'O':
        return y.swapcase()
    elif y == 'O':
        return x.swapcase()
    sign = (x.isupper() + y.isupper()) % 2
    if x.lower() == y.lower():
        return 'o' if sign else 'O'
    xy_lower = (x+y).lower()
    third = set('ijk').difference(xy_lower).pop()
    if xy_lower in order:
        return third.upper() if sign else third
    else:
        return third if sign else third.upper()
    
if __name__ == '__main__':
    with open(sys.argv[1], 'r') as f:
        T = int(f.readline())
        for test in range(1, T+1):
            debug(test)
            L, X = map(int, f.readline().split())
            s = f.readline().strip()
            if X < 12:
                s = s * X
            else:
                s = s * (8 + X % 4)
            done = False
            for h in range(4*L):
                if reduce(quater, s, 'o') != 'O':
                    print("Case #{}: NO".format(test))
                    done = True
                elif reduce(quater, s[:h], 'o') == 'i':
                    debug("h = {}\n{}".format(h, s[:h]))
                    for t in range(len(s)-1, max(h, len(s)-4*L-1), -1):
                        if reduce(quater, s[t:], 'o') == 'k':
                            debug("t = {}\n{}".format(t, s[t:]))
                            if reduce(quater, s[h:t], 'o') == 'j':
                                done = True
                                print("Case #{}: YES".format(test))
                                #print("\n".join([s[:h], s[h:t], s[t:]]))
                                break
                if done:
                    break
            if not done:
                print("Case #{}: NO".format(test))
