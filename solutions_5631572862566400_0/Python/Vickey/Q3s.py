#!/usr/bin/env python

import os
import re
import sys
import json
import copy
import time
import shlex
import traceback
import subprocess

def main():
    with open('C-small-attempt2.in.txt', 'r') as f: inp = f.read().split('\n')
    #with open('input.txt', 'r') as f: inp = f.read().split('\n')

    inp = inp[1:]
    inp = inp[1:len(inp):2]
    c = 0    
    for i in inp:
        if not i: continue

        mapping = [int(s) for s in i.split()]
        maxlen = 0
        for st in range(len(mapping)):
            processed = {}
            next = st+1
            prev = None
            first = st+1
            thislen = 0
            out = []
            circular = True

            while True:
                if processed.get(next) != None:
                    #print first, next, prev, mapping[next-1]
                    if first != next and prev != mapping[next-1]:
                        circular = False
                    break
                processed[next] = thislen
                out += [next]
                thislen += 1
                #print next, mapping[next-1]
                prev = next
                next = mapping[next-1]
            #print out
            #print first, next
            if not circular:
                last = len(out)
                for o in range(len(out)):
                    if mapping[out[len(out)-o-1]-1] == first:   break
                    if mapping[out[len(out)-o-1]-1] != out[len(out)-o-1]:
                        thislen -= 1
                        del processed[out[len(out)-o-1]]
                        last = len(out)-o
                out = out[:last]
                circular = True


            if circular and first != next:
                for s in range(len(mapping)):
                    if processed.get(s+1) == None:
                        '''
                        if first == mapping[s] and circular:
                            out = [mapping[s]]+out
                            processed[s+1] = thislen
                            thislen += 1
                            first = s
                        '''
                        
                        if out[-1] == mapping[s]:
                            out = out+[s+1]
                            processed[s+1] = thislen
                            thislen += 1
                            next = s
                        
            #print out
            #print circular
            if circular and maxlen<thislen:
                maxlen = thislen

        print 'Case #'+str(c+1)+': '+str(maxlen)#' '.join()
        c+=1

if __name__ == "__main__":
    main()