#!/usr/bin/env python3

################################################################################

def read_int():
    return int(input())

def read_words():
    return input().split()

def read_ints():
    return list(map(int,read_words()))

def read_floats():
    return list(map(float,read_words()))

################################################################################

def solve(X,R,C):
    r = max(R,C)
    c = min(R,C)

    p = r * c
    if p < X or p % X != 0:
        return False

    
    if X == 1 or X == 2:
        return True

    if X == 3:
        
        if r == 3 and (c == 2 or c == 3):
            return True
        if r == 4:
            return True

        return False
    
    if X == 4:
        return p > 11
        
if __name__ == "__main__":
    T = read_int()
    for c in range(T):
        [X,R,C] = read_ints()
        R = solve(X,R,C)
        if R:
            R = "GABRIEL"
        else:
            R = "RICHARD"
        print("Case #{}: {}".format(c+1,R))
