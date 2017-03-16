"""Code jam 2015, Qualification Round
Problem D. Ominous Omino
author: benfei
"""
from math import ceil, sqrt
def can_richard_win(X, R, C):
    if X == 1:
        return False

    MIN, MAX = min(R, C), max(R, C)
    if X >= 7:
        return True
    if (R * C) % X != 0:
        return True
    if X > MAX:
        return True
    if X == 2:
        return False
    if ceil(sqrt(X)) > MIN:
        return True
    if X == 3:
        return False
    if X == 4 and MIN == 2:
        return True
    if X == 4 and MIN > 2:
        return False
    if X == 5 and MIN == 3 and (1 + 3 * (MAX - 3)) % 5 != 0:
        return True
    if X == 5 and MIN > 3:
        return False
    if X == 6 and MIN == 3:
       return True
    if X == 6 and MIN == 4 and (3 + 4 * (MAX - 3)) % 6 != 0:
        return True
    if X == 6 and MIN == 4 and (1 + 4 * (MAX - 2)) % 6 != 0:
        return True
    if X == 6 and MIN > 4:
        return False
        
    return None

def parse_input():
    X, R, C = input().split(" ")
    X = int(X)
    R = int(R)
    C = int(C)

    return X, R, C

def print_result(x, y):
    print("Case #{x:d}: {y}".format(x=x, y=y))

def main():
    T = int(input())
    for test_case in range(1, T+1):
        X, R, C = parse_input()
        winner = "RICHARD" if can_richard_win(X, R, C) else "GABRIEL"
        print_result(test_case, winner)

def get_special_cases():
    count = 0
    for X in range(1, 21):
        for C in range(1, 21):
            for R in range(1, C+1):
                if can_richard_win(X, R, C) is None:
                    print("X={X:d}, R={R:d}, C={C:d}".format(X=X, R=R, C=C))
                    count += 1
    print("COUNT = {:d}".format(count))

if __name__ == "__main__":
    main()
    #get_special_cases()