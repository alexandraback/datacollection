#!/usr/bin/env python3

from math import log

def flip(S):
    # Reverse the string.
    Sr = reversed(S)

    # Start on +, since we'll need happy side up at the end.
    current = '+'

    # Iterate through the (reversed) string, counting the number of times
    # the current character changes.
    # e.g. '+++' -> 1; '---' -> 1, since we start on +.
    # '-+-' -> 3; '--+' -> 2; '++-' -> 1.
    nflips = 0
    for face in Sr:
        if face != current:
            current = face
            nflips += 1

    # Return the number of changes.
    return nflips

def oracle(S):
    assert(flip(S) < len(S)+1)
    if '-' in S:
        assert(flip(S) > 0)
        if '+-' in S:
            assert(flip(S) > 1)
            if '-+' not in S:
                assert(flip(S) == 2)
        else:
            assert(flip(S) == 1)
    else:
        assert(flip(S) == 0)


if __name__ == '__main__':

    T = int(input())
    for i in range(1, T+1):
        S = input()
        oracle(S)

        print("Case #{}: {}".format(i, flip(S)))
