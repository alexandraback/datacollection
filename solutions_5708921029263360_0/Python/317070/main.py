import glob, pprint, pickle, os, time, sys
from copy import copy
from numpy import array, sin, cos
import numpy as np
import itertools
import math
import itertools
import random
from collections import defaultdict




def solve(J,P,S,K):
    # you have every garment
    garments = list(itertools.product(xrange(J), xrange(P), xrange(S)))
    #print garments
    # from these garments, we need to remove each JP S-K times
    # to remove:
    to_rem_JP = (S-K)*list(itertools.product(xrange(J), xrange(P)))
    to_rem_JS = (P-K)*list(itertools.product(xrange(J), xrange(S)))
    to_rem_PS = (J-K)*list(itertools.product(xrange(P), xrange(S)))

    lim_score = [J*P+J*S+P*S, J*P+J*S, J*P+P*S, J*S+P*S, J*P, J*S, P*S]
    sorted(lim_score)
    for lim_score in lim_score:
        for j in xrange(J):
            for p in xrange(P):
                for s in xrange(S):
                    found = True
                    while found and (j,p,s) in garments:
                        score = 0

                        if (j,p) in to_rem_JP:
                            score += J*P
                        if (j,s) in to_rem_JS:
                            score += J*S
                        if (p,s) in to_rem_PS:
                            score += P*S

                        if score==lim_score:
                            found = True
                            garments.remove((j,p,s))
                            if (j,p) in to_rem_JP:
                                to_rem_JP.remove((j,p))
                            if (j,s) in to_rem_JS:
                                to_rem_JS.remove((j,s))
                            if (p,s) in to_rem_PS:
                                to_rem_PS.remove((p,s))
                        else:
                            found = False

    return (len(garments),garments)


    # greedy search
    """
    d = [J*P, J*S, P*S]
    if P*S>J*P:
        d[2] = np.inf
    if J*S>J*P:
        d[1] = np.inf
    found = True
    while found:
        found = False
        minscore = 1e9
        minresult = None

        for j in xrange(J):
            for p in xrange(P):
                for s in xrange(S):
                    if JP_dict.get((j,p), 0)<K and PS_dict.get((p,s), 0)<K and JS_dict.get((j,s), 0)<K and (j,p,s) not in garments:
                        found = True
                        curr = (JP_dict.get((j,p), 0), PS_dict.get((p,s), 0), JS_dict.get((j,s), 0))
                        if sum(np.array(curr) / np.array(d)) < minscore:
                            minscore = sum(curr)
                            minresult = (j,p,s)

        if found:
            (j,p,s) = minresult
            garments.append((j,p,s))
            JP_dict[(j,p)]=JP_dict.get((j,p), 0)+1
            PS_dict[(p,s)]=PS_dict.get((p,s), 0)+1
            JS_dict[(j,s)]=JS_dict.get((j,s), 0)+1

    """


    return (len(garments),garments)

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
        (J,P,S,K) = read_ints()
        answer, solution = solve(J,P,S,K)

        ### output ###
        answer_str = "Case #{}: {}".format(questionindex+1, answer)
        for i,j,k in solution:
            answer_str += "\n{} {} {}".format(i+1,j+1,k+1)
        output += answer_str + '\n'
        print answer_str

ofile = open('output', 'w').write(output)
TOC = time.time()