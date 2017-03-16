import glob, pprint, pickle, os, time, sys
from copy import copy
from numpy import array, sin, cos
import itertools
import math

def solve(K,C,S):

    # suppose
    search_positions = []
    for i in xrange(1,K+1,C):
        if i+C-1<=K:
            L_list = range(i,i+C-1)[::-1] #C-1 lang
            G = i+C-1
        else:
            L_list = range(i,K)
            G = K
            if L_list:
                while len(L_list)<C-1:
                    L_list.append(L_list[0])
            else:
                L_list = [G]*(C-1)
            L_list = L_list[::-1]
        #print L_list, G
        if not L_list:
            search_on = G
        else:
            search_on = 0
            while L_list:
                l = L_list.pop()
                search_on = (search_on + l - 1)*K
            search_on = search_on+G
        search_positions.append(search_on)
    if len(search_positions)>S:
        return ("IMPOSSIBLE",)
    return search_positions

def printme(K,C,S):
    from itertools import product
    for orig in product('LG', repeat=K):
        if 'G' not in orig:
            continue
        orig = ''.join(orig)
        s = orig
        for _ in xrange(C-1):
            s = s.replace('G','G'*K)
            s = s.replace('L',orig)
        yield s

def test(K,C,S, answer):
    for setup in printme(K,C,S):
        found = False
        for p in answer:
            if setup[p-1]=="G":
                found = True
                break
        if not found:
            print "%s not found in here: \n%s" % (str(answer), setup)
            print
            for setup in printme(K,C,S):
                print setup

output = ""
TIC = time.time()
with open(sys.argv[1] if len(sys.argv) > 1 else "default.in") as f:
    def read_ints():
        return [int(x) for x in f.readline().strip().split(' ')]
    def read_frac():
        return [int(x) for x in f.readline().strip().split('/')]
    def read_strs():
        return [x for x in f.readline().strip().split(' ')]
    def read_floats():
        return [float(x) for x in f.readline().strip().split(' ')]

    (numquestions,) = read_ints()
    for questionindex in xrange(numquestions):

        ### calculate answer ###
        K,C,S = read_ints()
        answer = solve(K,C,S)
        #test(K,C,S, answer)
        ### output ###
        answer_str = "Case #{}: {}".format(questionindex+1, " ".join([str(a) for a in answer]))
        output += answer_str + '\n'
        print answer_str

ofile = open('output', 'w').write(output)
TOC = time.time()