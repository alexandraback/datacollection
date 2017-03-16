#!/usr/bin/python

import sys
import functools
import operator


def solve(preds):
    n = len(preds)
    #print(preds)
    for i in range(n):
        #print("--------------------")
        #print(i)
        p = []
        np = list(preds[i])
        while np:
            #print("p: " + str(p))
            #print("np: " + str(np))
            a = np.pop(0)
            if a in p:
                return "Yes"
            else:
                p.append(a)
                #print(preds)
                #print("preds at " + str(a) + ": "+ str(preds[a]))
                np.extend(preds[a])
    return "No"

def findPreds(succs):
    n = len(succs)
    #print(succs)
    preds = []
    for i in range(n):
        preds.append([])
        for j in range(n):
            if i in succs[j]:
                preds[i].append(j) 
    return preds


def main():
    N = int(sys.stdin.readline()) # number of testcases
    for i in range(N):
        # use something like:
        # sys.stdin.readline()
        # [int(x) for x in sys.stdin.readline().split()]
        num_nodes = int(sys.stdin.readline())
        succs = [None] * num_nodes
        for j in range(num_nodes):
            succs[j] = [int(x) - 1 for x in sys.stdin.readline().split()[1:]]
        preds = findPreds(succs)
        result = solve(preds)
        print ("Case #%s: %s" % (i+1, result))


if __name__ == '__main__':
    main()
