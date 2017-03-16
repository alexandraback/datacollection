#! /usr/bin/python

import sys

def evaluate(base, string):
    ret = 0
    for c in string:
        ret *= base
        ret += c
    return ret

def solve(lines, idx):
    line = lines[idx]
    nums = line.strip().split(" ")
    k = int(nums[0])
    c = int(nums[1])
    s = int(nums[2])

    if c * s < k:
        return "IMPOSSIBLE", 1

    needed = list(range(k))

    sols = set()
    while len(needed) > 0:
        next_sol, needed = needed[:c], needed[c:]
        sols.add(str(evaluate(k, next_sol)+1))
    
    return " ".join(sols), 1

def main():
    fn = sys.argv[1] 
    with open(fn) as f:
        lines = f.readlines()
    t = int(lines[0])
    idx = 1
    for i in range(t):
        result, num_used = solve(lines, idx)
        idx += num_used
        print "Case #%d: %s" % (i+1, result)

if __name__ == "__main__":
    main()
