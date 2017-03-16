#!/usr/bin/env python2
# -*- coding: utf-8 -*-

import sys

def compute_tree(tab, r):
    fire = [0]*(len(tab)+1)
    l = [r]
    while len(l) != 0:
        e = l.pop()
        for k in tab[e-1]:
            if fire[int(k)] != 0:
                return True
            fire[int(k)] = 1
            l.append(int(k))
    return False
    
def compute(tab):
    fire = [0]*(len(tab)+1)
    root = []
    for i in range(len(tab)):
        for k in tab[i]:
            fire[int(k)] = 1
    for i in range(1, len(fire)):
        if fire[i] == 0:
            root.append(i)
    for r in root:
        if compute_tree(tab, r):
            return "Yes"
            
    return "No"

f=open(sys.argv[1])
lines=f.read().split("\n")
nb_lines=int(lines[0])
lines=lines[1:]

line_num = 0
for i in range(nb_lines):
    j = int(lines[line_num])
    line_num += 1
    tab = []
    for k in range(j):
        tab.append(lines[line_num].split(" ")[1:])
        line_num += 1
    print("Case #%d: %s" % (i+1, compute(tab)))
