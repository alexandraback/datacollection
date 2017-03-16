#!/usr/bin/python3

from argparse import ArgumentParser
#from pprint import pprint
from string import ascii_lowercase as alpha

p = ArgumentParser()
p.add_argument('filename')
p.add_argument('-v', '--verbose', action='store_true')
p.add_argument('-n', '--limit', type=int)
opts = p.parse_args()
verbose = opts.verbose
f = open(opts.filename)

T = int(f.readline())
if opts.limit is not None and T > opts.limit:
    T = opts.limit

def debug(*args, **kwargs):
    if verbose:
        print(*args, **kwargs)
def pdebug(*args, **kwargs):
    if verbose:
        pprint(*args, **kwargs)

plain = (
'ourlanguageisimpossibletounderstand'
'therearetwentysixfactorialpossibilities'
'soitisokayifyouwanttojustgiveup'
)

cipher = (
'ejpmysljylckdkxveddknmcrejsicpdrysi'
'rbcpcypcrtcsradkhwyfrepkymveddknkmkrkcd'
'dekrkdeoyakwaejtysrreujdrlkgcjv'
)

d = {'y':'a', 'e':'o', 'q':'z'}
d['z'] = 'q' # by process of elimination

for p,c in zip(plain,cipher):
    if d.setdefault(c, p) is None:
        raise ValueError('%c already mapped to %c' % (c, d[c]))

if verbose:
    print(alpha)
    print(''.join(d.get(c,'?') for c in alpha))

for casenum in range(1,T+1):
    message = f.readline()
    output_str = ''.join(d.get(c,c) for c in message)
    print('Case #%d:'%casenum, output_str, end='')
