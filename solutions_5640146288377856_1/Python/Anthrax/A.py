#!/bin/env python3

def solution(R,C,W):
    #print(R,C,W)
    #print(R*[C*[1]])

    lastrow = (C//W)-1

    # Find ship
    N = (C%W) + W

    if W == N:
        lastrow += W
    else:
        lastrow += W+1

    return ((C//W)*(R-1)+lastrow,)

#%% Main and input handling

def main():
    T = int(input())
    
    for t in range(T):
        do_case(t+1)

def do_case(t):
    R,C,W = [int(x) for x in input().split()]
    
    answers = solution(R,C,W)
    print_case(t, answers)
    
def print_case(t,answers):
    print("Case #%d: %d" % ((t,)+answers))

if __name__ == "__main__":
    main()
