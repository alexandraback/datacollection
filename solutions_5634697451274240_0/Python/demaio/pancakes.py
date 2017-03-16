#! /usr/bin/python

import sys

def solve(lines, idx):
    num_inversions = 0
    old_c = '+'
    for c in lines[idx].strip()[::-1]:
        if c != old_c:
            num_inversions += 1
            old_c = c
    return num_inversions, 1

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
