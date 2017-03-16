#! /usr/bin/python

import sys
import random

def gen_str(digits):
    bits = random.getrandbits(digits* 100)
    bitstring = '{0:08b}'.format(bits)
    bitstring = bitstring[:digits]
    ret = [int(c) for c in bitstring]
    ret[0] = 1
    ret[-1] = 1
    return tuple(ret)

def evaluate(base, string):
    res = 0
    for c in string:
        res *= base
        res += c
    return res

def solve(lines, idx):
    line = lines[idx]
    nums = line.strip().split(" ")
    small_div = [2, 3, 5, 7, 11, 13, 17, 19]
    n = int(nums[0])
    j = int(nums[1])

    used_strings = set()
    sols = set()
    while len(sols) < j:
        string = gen_str(n)
        if string in used_strings:
            continue
        sol = (string, [])
        bad_sol = False
        for base in range(2, 11):
            number = evaluate(base, string)
            bad_base = True
            for div in small_div:
                if number % div == 0:
                    sol[1].append(div)
                    bad_base = False
                    break
            if bad_base:
                bad_sol = True
                break
        if bad_sol:
            continue
        sols.add((sol[0], tuple(sol[1])))
        used_strings.add(string)
    
    sol_string = "\n"
    for sol in sols:
        bitss = [str(c) for c in sol[0]]
        bits = "".join(bitss)
        sol_string += str(bits) + " "
        for div in sol[1]:
            sol_string += str(div) + " "
        sol_string += "\n"
    return sol_string, 1

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
