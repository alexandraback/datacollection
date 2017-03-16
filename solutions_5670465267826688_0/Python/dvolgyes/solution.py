#!/usr/bin/python
import sys
import numpy as np     # http://www.numpy.org/
import scipy           # http://scipy.org/
import networkx as nx  # https://networkx.github.io/
import sympy           # http://www.sympy.org

N = int(sys.stdin.readline())

solutions = []

signs = {
    ("1", "1"): 1,
    ("1", "i"): 1,
    ("1", "j"): 1,
    ("1", "k"): 1,
    ("i", "1"): 1,
    ("i", "i"): -1,
    ("i", "j"): 1,
    ("i", "k"): -1,
    ("j", "1"): 1,
    ("j", "i"): -1,
    ("j", "j"): -1,
    ("j", "k"): 1,
    ("k", "1"): 1,
    ("k", "i"): 1,
    ("k", "j"): -1,
    ("k", "k"): -1,
}


matrix = {
    ("1", "1"): "1",
    ("1", "i"): "i",
    ("1", "j"): "j",
    ("1", "k"): "k",
    ("i", "1"): "i",
    ("i", "i"): "1",
    ("i", "j"): "k",
    ("i", "k"): "j",
    ("j", "1"): "j",
    ("j", "i"): "k",
    ("j", "j"): "1",
    ("j", "k"): "i",
    ("k", "1"): "k",
    ("k", "i"): "j",
    ("k", "j"): "i",
    ("k", "k"): "1",
}


def minimal_form(string, N=1):
    sign = 1
    value = "1"
    for c in string:
        sign *= signs[value, c]
        value = matrix[value, c]

    if N > 1:
        s, v = minimal_form(value * N)
        sign = sign if N % 2 == 1 else 1
        sign *= s
        value = v
    return sign, value

def first_match(string,ts,target):
    sign = 1
    value = "1"
    l = len(string)
    for i in range(0,l):
        sign *= signs[value, string[i]]
        value = matrix[value, string[i]]
	if (sign,value) == (ts,target): return i,ts,target
    return l,sign,value

def test():
    for c1 in "1ijk":
        s = ""
        for c2 in "1ijk":
            si = " " if signs[(c1, c2)] > 0 else "-"
            s += si + matrix[(c1, c2)] + " "
    print s
    sys.exit(1)

for case in range(0, N):
    solution = ""
    L, X = map(int, sys.stdin.readline().strip().split())
    string = sys.stdin.readline().strip()

    if minimal_form(string, X) != minimal_form("ijk"):
        solution = "NO"
    else:
        solution = "YES"
	LEN = L*X
	longstring = string * X
	l,s,v = first_match(longstring,1,"i")
	if (l+1>=L*X) or ( (s,v)!=(1,"i")):
	    solution = "NO"
	else:
		longstring = string * X
	#search for j
		l2,s2,v2 = first_match(longstring[l+1:],1,"j")
		if l2+l+2>=L*X:
		    solution = "NO"
		    
    solutions.append(solution)

for case in range(0, N):
    print "Case #%i: %s" % (case + 1, solutions[case])
