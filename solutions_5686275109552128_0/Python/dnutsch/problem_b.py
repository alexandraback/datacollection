#1/usr/bin/python

from collections import OrderedDict
import heapq
from math import ceil

f = open('B-small-attempt0.in','r');
out = open('B-small-attempt0.out','w');
T = int(f.readline().strip())

def ceildiv(a, b):
    return -(-a // b)


def increase(a):
    n = freq.get(a,0) + 1
    freq[a]=n
    return n

def decrease(a):
    if freq.has_key(a):
        n = freq.get(a,0) - 1
        freq[a]=n
        return n
    else:
        return 0


for t in xrange(0,T):
    D = int(f.readline().strip())
    p = [int(x) for x in f.readline().strip().split(' ') ]


    freq = dict()

    for val in p:
        increase(val)

    max_stack = max(p);
    minutes= 0;
    while max_stack > 0:
        sorted_keys = sorted(freq.keys(), reverse=True)
        a = sorted_keys[0]
        dist = 0
        if len(sorted_keys) == 1:
            print "one number"
            dist = a # stacks of a packakes to eat
            fr = freq[a]
            if fr < dist:
                print "splitting one {}".format(a)
                half = ceildiv(a,2)
                # move half the stack to another stack
                if fr %2 == 1:
                    freq[half] = freq.get(half,0) + 1
                    freq[half-1] = freq.get(half-1,0) + 1
                    max_stack = half;
                else:
                    freq[half] = freq.get(half,0) + 2
                    max_stack = half
                # stack was split, reduce the freq
                newfreq = fr -1;
                if (newfreq > 0):
                    freq[a]= newfreq
                else:
                    del freq[a]
            else:
                print "eating"
                # else, eat
                max_stack = 0
                newfreqs = dict()
                for x in freq.items():
                    a = x[0] - 1
                    if a > max_stack:
                        max_stack = a
                    if a > 0:
                        newfreqs[a] = x[1]
                freq = newfreqs;
        else:
            b = sorted_keys[1]
            half = ceildiv(a,2)
            cdown = a - max(b,half)
            fr = freq[a]

            # split a stack if frequency is less that the eatdown
            if fr < cdown:
                print "splitting because freq {} is less than dist {}".format(fr,cdown)
                # move half the stack to another stack
                if fr %2 == 1:
                    freq[half] = freq.get(half,0) + 1
                    freq[half-1] = freq.get(half-1,0) + 1
                else:
                    freq[half] = freq.get(half,0) + 2
                # stack was split, reduce the freq
                newfreq = freq.get(a,0) -1;
                if (newfreq > 0):
                    freq[a]= newfreq
                else:
                    del freq[a]
            else:
                print "eating"
                # else, eat
                max_stack = 0
                newfreqs = dict()
                for x in freq.items():
                    a = x[0] - 1
                    if a > max_stack:
                        max_stack = a
                    if a > 0:
                        newfreqs[a] = x[1]
                freq = newfreqs;
        minutes += 1
    print "Case #{}: p= {}, {}".format(t+1, p, minutes)
    out.write ("Case #{}: {}\n".format(t+1, minutes))

