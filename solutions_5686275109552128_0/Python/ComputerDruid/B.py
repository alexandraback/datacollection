#!/usr/bin/env python3

def total_steps_needed_for(target, stacks):
    return sum(( (x-1)//target + 1 - 1 for x in stacks )) + target

def num_steps(stacks):
    max_val = max(stacks)
    steps_needed = ( total_steps_needed_for(target, stacks) for target in range(1, max_val + 1) )
    return min(steps_needed)

def main():
    T = int(input())
    for t in range(T):
        num_stacks = int(input())
        stacks = [ int(x) for x in input().split(" ") ]
        print("Case #" + str(t + 1) + ": " + str(num_steps(stacks)))

if __name__ == '__main__':
    main()
