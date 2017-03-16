#!/usr/local/Cellar/python3/3.2.2/bin/python3
from GCJ import GCJ
import math

def solve(infile):
    A, N = GCJ.readints(infile)
    ms = sorted(GCJ.readintarray(infile))
    if A == 1:
        return len(ms)
    return count(A, 0, ms)
    
    
def grow_to_eat(size, aim):
    n = 0
    while size <= aim:
        size += (size-1)
        n += 1
    return size, n

def count(size, pos, ms):
    if pos == len(ms):
        return 0
        
    if ms[pos] >= size:
        size, n = grow_to_eat(size, ms[pos])
        if len(ms) - pos <= n: # Weiter wachsen lohnt sich nicht, einfach alle entfernen
            return len(ms) - pos

        res = count(size+ms[pos], pos+1, ms) + n 
        if res >= len(ms) - pos: # 
            return len(ms) - pos
        else:
            return res
    else:
        return count(size+ms[pos], pos+1, ms)

if __name__ == "__main__":
    GCJ("A", solve).run()




