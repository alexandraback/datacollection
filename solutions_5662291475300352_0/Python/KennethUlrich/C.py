import argparse
import collections
import fractions
import functools
import itertools
import math
import operator

from sys import exit, stdin
from multiprocessing import Pool

def solve_star(args):
    return solve(*args)

def read_int():
    return int(stdin.readline().strip())

def read_ints():
    return [int(n) for n in stdin.readline().strip().split()]

def read_floats():
    return [float(n) for n in stdin.readline().strip().split()]

def read_words():
    return stdin.readline().strip().split()

def parse():
    result = []
    for n in range(read_int()):
        d, h, s = read_ints()
        for i in range(h):
            result.append([d, s + i])
    return [result]

def solve(v):
    t = 0
    lowest_deg = sorted(v)[0][0]
    behind = None
    for i in range(len(v)):
        if v[i][0] == lowest_deg:
            behind = i
            break
    meetings = 0
    while True:
        #print("behind", behind)
        #print(v)
        next_meet = []
        for i in range(len(v) - 1):
            i_d, i_s = v[i]
            for j in range(i + 1, len(v)):
                j_d, j_s = v[j]
                #print("vi, vj", v[i], v[j])
                delta = i_s / j_s
                #print("delta is", delta)
                if delta != 0:
                    next_meet.append((min(i_s, j_s) / delta, i, j))
        #print(next_meet)
        next_meet.sort()
        if not next_meet:
            return 0
        for k in range(len(v)):
            #print ("hmm")
            v[k][0] = (v[k][0] + 360 * (next_meet[0][0] / v[k][1]))
            #print(k, v[k][0], behind)
            if behind == k and v[k][0] >= 360:
                return meetings
            v[k][0] = v[k][0] % 360
        a, b = next_meet[0][1], next_meet[0][2]
        if behind in (a, b):
            behind = a if (v[a][1] < v[b][1]) else b
            meetings += 1

        




if __name__ == "__main__":
    
    parser = argparse.ArgumentParser()
    parser.add_argument("-m", "--multi", help="turn on multiprocessing", action="store_true")
    args = parser.parse_args()
    
    with open("out.txt", "w") as f:
        if args.multi:
            pool = Pool()
            iter = pool.imap(solve_star, (parse() for i in range(read_int())))
            for i, result in enumerate(iter):
                s = "Case #{}: {}".format(i + 1, result)
                print(s)
                f.write(s + "\n")
        
        else:
            for i in range(read_int()):
                s = "Case #{}: {}".format(i + 1, solve(*parse()))
                print(s)
                f.write(s + "\n")
