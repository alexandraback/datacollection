#!/usr/bin/python

import math
import sys

def is_pal(n):
    s = str(n)
    def pal_aux(s):
        if s == '':
            return True
        if len(s) == 1:
            return True
        if s[0] == s[-1]:
            return pal_aux(s[1:-1])
        return False
    return pal_aux(s)

def main():
    data = sys.stdin.readlines()
    data.pop(0) # T  
    for lineno, line in enumerate(data):
        n = 0
        sp = line.split(" ")
        x = int(math.ceil(math.sqrt(int(sp[0]))))
        y = int(math.sqrt(int(sp[1])))
        for i in range(x,y+1):
            if not is_pal(i):
                continue
            if is_pal(i*i):
                n += 1
        print("Case #%d: %d" % (lineno+1, n))

if __name__ == '__main__':
    main()
