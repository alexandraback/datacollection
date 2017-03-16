import glob, pprint, pickle, os, time, sys
from copy import copy
from numpy import array, sin, cos
import numpy as np
import itertools
import math
import itertools
import random
from collections import defaultdict




def solve(topiclist):

    not_fake = []
    definitely_fake = []
    found = False

    PRINT = True


    for idx,t in enumerate(topiclist):
        first = sum([topic[0]==t[0] for topic in topiclist if (topic is not t)])
        second = sum([topic[1]==t[1] for topic in topiclist if (topic is not t)])
        if first==0 or second==0:
            if PRINT:
                print t,"is not fake A"
            not_fake.append(t)

    while len(not_fake)+len(definitely_fake) < len(topiclist):
        if PRINT:
            print "fake", definitely_fake
            print "not fake", not_fake
        # step 1: sort by who generates most:
        generates = [0]*len(topiclist)
        first = set([topic[0] for topic in not_fake])
        second = set([topic[1] for topic in not_fake])

        for idx,t in enumerate(topiclist):
            generates[idx] = (sum([(topic[0]==t[0] and t[0] not in first and topic[1] in second) or (topic[1]==t[1] and t[1] not in second and topic[0] in first) for topic in topiclist
                                  if (topic is not t) and (topic not in definitely_fake) and (topic not in not_fake)]),
                              sum([(topic[0]==t[0] and t[0] not in first) or (topic[1]==t[1] and t[1] not in second) for topic in topiclist
                                  if (topic is not t) and (topic not in definitely_fake) and (topic not in not_fake)]),
                               )

        generates, topiclist = zip(*sorted(zip(generates, topiclist),reverse=True))

        found = False
        for idx,t in enumerate(topiclist):
            if t in definitely_fake or t in not_fake:
                continue
            if t[0] in first and t[1] in second:
                if PRINT:
                    print t,"is fake D"
                definitely_fake.append(t)
                found = True

        if not found:
            # add one probably not fake
            found = False
            for idx,t in enumerate(topiclist):
                if t in definitely_fake or t in not_fake:
                    continue
                first = set([topic[0] for topic in not_fake])
                second = set([topic[1] for topic in not_fake])
                if t[0] not in first or t[1] not in second:
                    if PRINT:
                        print t,"is not fake C"
                    not_fake.append(t)
                    found = True
                    break

    return (len(definitely_fake),)

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
        (numtopics,) = read_ints()
        topiclist = []
        for _ in xrange(numtopics):
            topics = read_strs()
            topiclist.append(topics)
        answer = solve(topiclist)

        ### output ###
        answer_str = "Case #{}: {}".format(questionindex+1, " ".join([str(a) for a in answer]))
        output += answer_str + '\n'
        print answer_str

ofile = open('output', 'w').write(output)
TOC = time.time()