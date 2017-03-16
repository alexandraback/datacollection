# coding: utf-8

import sys
import itertools

def isvowel(c):
    return c in "aeiou"

def calc2(s, n):
    iscon = False
    con = 0
    ans = 0
    last = -1
    
    # print("-------------")
    for i, c in enumerate(s):
        if isvowel(c):
            con = 0
            ans += last + 1
        else:
            con += 1
            if con >= n:
                ans += (i+1) - n + 1
                last = i - n + 1
            else:
                ans += max(0, last + 1)

        # print("@", i, c)
        # print("ans:%d" % (ans))

    return ans
        
def main():
    ncases = int(sys.stdin.readline())

    for cc in range(ncases):
        s, n = sys.stdin.readline().split()

        print("Case #%d: %d" % (cc+1, calc2(s, int(n))))
        
        
if __name__ == "__main__":
    main()
