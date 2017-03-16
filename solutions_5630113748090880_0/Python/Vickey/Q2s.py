#!/usr/bin/env python

import os
import re
import sys
import json
import time
import shlex
import traceback
import subprocess

def main():
    with open('B-small-attempt1.in.txt', 'r') as f: inp = f.read().split('\n')

    inpt = inp[1:]
    cs = 0
    c = 0
    while cs<len(inpt):
        if not inpt[cs].strip(): break

        inp = inpt[cs+1:cs+2*int(inpt[cs])]
        cl = int(inpt[cs])
        cs += 2*int(inpt[cs])
        listnumbers = {}
        for i in inp:
            if not i: continue

            #print [int(n) for n in i.split()]
            for n in i.split():
                num = int(n)
                if listnumbers.get(n):
                    listnumbers[n] += 1
                else:
                    listnumbers[n] = 1

        final = []
        for l in listnumbers:
            if listnumbers[l]%2 != 0:
                final += [int(l)]

        if len(final) != cl:
            print 'here', len(final),len(inp)
            break
        print 'Case #'+str(c+1)+': '+' '.join([str(s) for s in sorted(final)])
        c+=1

if __name__ == "__main__":
    main()