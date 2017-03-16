# -*- coding: utf-8 -*-
"""
Created on Sun May  8 12:36:45 2016

@author: Eidan Cohen
"""



def mem_handle(mem, a, b , c, k):
    r1, r2, r3 = mem[0].get((a,b), 0), mem[1].get((b,c), 0), mem[2].get((a,c), 0)
    if r1 == k or r2 == k or r3 == k:
        return False
    mem[0][(a,b)] = r1 + 1
    mem[1][(b,c)] = r2 + 1
    mem[2][(a,c)] = r3 + 1
    return True

def solve(j,p,s,k):
    result = ""
    count = 0
    mem = [dict(), dict(), dict()]
    for a in range(j):
        for b in range(p):
            for c in range(s):
                if mem_handle(mem,a,b,c, k):
                    count += 1
                    result += "\n{0} {1} {2}".format(a+1,b+1,c+1)
    return str(count) + result
    
def main():
    t = int(input())
    for i in range(1,t+1):
        j,p,s,k = tuple(int(x) for x in input().split(" "))
        print('Case #{0}: {1}'.format(i, solve(j,p,s,k)))

if __name__ == '__main__':
    main()
