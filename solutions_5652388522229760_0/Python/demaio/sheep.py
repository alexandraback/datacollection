#! /usr/bin/python

import sys

def digits(n):
    ret = set()
    while n > 0:
        ret.add(n % 10)
        n = n // 10
    return ret

def solve(lines, idx):
    n = int(lines[idx])
    if n == 0:
        return "INSOMNIA", 1

    target_set = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9}
    actual_set = set()
    k = 0

    while actual_set != target_set:
        k += 1
        actual_set |= digits(n * k)

    return n * k, 1

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
