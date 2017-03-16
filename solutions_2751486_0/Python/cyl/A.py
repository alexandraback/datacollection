import sys
import math
import decimal

T = int(sys.stdin.readline())

for i in range(T):

    vowels = ['a', 'e', 'i', 'o', 'u']
    name, n = sys.stdin.readline().strip().split(' ')
    n = int(n)
    ans = set()
    #seeds = []
    
    buf = 0
    for idx, c in enumerate(name):
        if c not in vowels:
            buf += 1
            if buf >= n:
                #seeds.append( (c - n + 1, c) )
                for a in range(idx - n + 2):
                    for b in range(idx, len(name)):
                        ans.add( (a, b) )
        else:
            buf = 0
    #print ans
    print "Case #" + str(i+1) + ": " + str(len(ans))
