#!/usr/bin/env python3

def solve_case(pancakes):
    pancakes = pancakes[::-1]
    flips = 0
    change_pos = pancakes.find('-') 
    while change_pos != -1:
        flips += 1
        change_pos = pancakes.find('-' if flips % 2 == 0 else '+', 
                                   change_pos)
    return flips

def main():
    T = int(input())
    for ci in range(1, T+1):
        print("Case #{}: {}".format(ci, solve_case(input())))

if __name__ == '__main__':
    main()
