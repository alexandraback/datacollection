#!/usr/bin/env python

import os
import re
import sys
import json
import time
import math
import shlex
import traceback
import subprocess

def main():
    #with open('input.txt', 'r') as f: inp = f.read().split('\n')
    with open('A-large.in.txt', 'r') as f: inp = f.read().split('\n')

    inp = inp[1:]
    for c,i in enumerate(inp):
        if not i: continue
        i = [w for w in i]
        final = [i[0]]  
        for w in i[1:]:
            if w>=final[0]:
                final = [w]+final
            #elif w<=final[-1]:
            else:
                final = final+[w]
        #s = reversed(sorted(i))

        print 'Case #'+str(c+1)+': '+''.join(final)

if __name__ == "__main__":
    main()