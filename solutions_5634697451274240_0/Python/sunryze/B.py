'''
Created on 09.04.2016

@author: dw
'''
import sys
from collections import deque

def read_input(filename):
    lines = open(filename).readlines()[1:]
    return [tuple(1 if c == '+' else -1 for c in line.strip()) for line in lines]
        
def flip(s, i):
    return tuple(n * -1 for n in s[:i][::-1]) + s[i:]

def process_case(s):
    wl = deque([(s, 0)])
    seen = set()
    l = len(s)
    while len(wl) > 0:
        s, d = wl.popleft()
        if -1 not in s:
            return d
        else:
            for i in range(l):
                if i == l-1 or s[i] != s[i+1]:
                    c = flip(s, i+1)
                    if c not in seen:
                        wl.append((c, d+1))
                        seen.add(c)

if __name__ == '__main__':
    infile = sys.argv[1]
    outfile = (infile[:-3] if infile.endswith('.in') else infile) + '.out'
    with open(outfile, 'w') as f_out:
        for i, inp in enumerate(read_input(infile)):
            line = 'Case #%d: %s' % (i+1, process_case(inp)) 
            print(line)
            f_out.write(line + '\n')