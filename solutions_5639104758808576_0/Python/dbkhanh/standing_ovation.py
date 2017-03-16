#!/usr/bin/env python

import os, sys

def solve(line):
    sline = line.split()
    s_max = int(sline[0])
    s_counts = [int(i) for i in sline[1]]
    num_less_shy = 0
    num_guests = 0
    for s, s_count in enumerate(s_counts):
        if s_count == 0: continue
        if num_less_shy >= s:
            num_less_shy += s_count
        else:
            num_new_guests = s - num_less_shy
            num_guests += num_new_guests
            num_less_shy += s_count + num_new_guests

    return num_guests

def main():
    lines = open(sys.argv[1]).read().rstrip().splitlines()
    N = int(lines[0])
    for case in range(1, N+1):
        answer = solve(lines[case])
        print("Case #{}: {}".format(case, answer))

if __name__ == "__main__":
    main()
