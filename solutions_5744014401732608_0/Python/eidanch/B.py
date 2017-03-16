# -*- coding: utf-8 -*-
"""
Created on Sun May  8 12:29:43 2016

@author: Eidan Cohen
"""

def build(b,m, last):
    if b == 1:
        return (m-1), [(0, last)]
    rm, edges = build(b-1, m, last)
    #print(b,rm, edges)
    i = 0
    edges.append((b-1, last))    
    while rm > 0 and i < b - 1:
        rm -= 1
        edges.append((i, b-1))  
        i += 1
    return rm, edges

def solve(b,m):
    rm, edges = build(b-1, m, b-1)
    edges = set(edges)
    if rm > 0:
        return "IMPOSSIBLE"
    result = "POSSIBLE"
    for i in range(b):
        result += "\n"
        for j in range(b):
            if (i,j) in edges:
                result += "1"
            else:
                result += "0"
    return result
        
def main():
    t = int(input())
    for i in range(1,t+1):
        b,m = tuple(int(x) for x in input().split(" "))
        print('Case #{0}: {1}'.format(i, solve(b,m)))

if __name__ == '__main__':
    main()
