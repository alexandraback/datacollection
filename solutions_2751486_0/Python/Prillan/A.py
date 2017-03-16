##
# CODEJAM
# prillan91
##
import sys
import re
import math

VOWELS = {"a", "o", "i", "e", "u"}
CONSONANTS = {chr(x) for x in range(ord("a"), ord("z") + 1) 
              if chr(x) not in VOWELS}

def solveSingle(f):
    s, n = f.readline().strip().split(" ")
    n = int(n)
    
    nval = 0
    for start in range(len(s)+1 - n):
        for end in range(start+n, len(s)+1):
            consec = 0
            s2 = s[start:end]
            for j in range(len(s2)):
                if s2[j] in CONSONANTS:
                    consec += 1
                    if consec >= n:
                        break
                else:
                    consec = 0
            if consec >= n:
                nval += 1

    return nval

def solve():
    f = open(sys.argv[1])
    o = open(sys.argv[1] + ".out", 'w')
    T = int(f.readline())

    for t in range(T):
        print t + 1
        o.write("Case #" + str(t + 1) + ": " + str(solveSingle(f)) + "\n")
        

if __name__ == "__main__":
    if len(sys.argv) == 1:
        prepare()
    else:
        solve()
