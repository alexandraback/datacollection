import sys
import math
import decimal

T = int(sys.stdin.readline())

for i in range(T):

    vowels = ['a', 'e', 'i', 'o', 'u']
    line = sys.stdin.readline().strip()
    name, n = line.split(' ')
    n = int(n)
    ans = 0

    #cur_sec = 0
    cur_idx = 0
    
    buf = 0
    for idx, c in enumerate(name):
        if c not in vowels:
            buf += 1
            if buf >= n:
                ans += (idx - n + 1 - cur_idx + 1)*(len(name) - idx)
                #cur_sec += 1
                cur_idx = idx - n + 2
        else:
            buf = 0
    print "Case #" + str(i+1) + ": " + str(ans)

