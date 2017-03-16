#!/usr/bin/env python3

def solve_case(N):
    num = N
    seen_digits = set(str(num))
    while len(seen_digits) < 10:
        num += N
        seen_digits.update(str(num))
    return num 

def main():
    T = int(input())
    for ci in range(1, T+1):
        N = int(input()) 
        if N == 0:
            print("Case #{}: INSOMNIA".format(ci))
        else:
            print("Case #{}: {}".format(ci, solve_case(N)))
        
if __name__ == '__main__':
    main() 
