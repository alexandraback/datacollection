#!/usr/bin/python3
# -*- coding: utf-8 -*-

def solve():
    m = [input() for _ in range(4)]
    input()
    def check(line,el):
        for x in line:
            if x!='T' and x!=el:
                return False
        return True
    lines = m + list(zip(*m)) + [m[0][0]+m[1][1]+m[2][2]+m[3][3],m[0][3]+m[1][2]+m[2][1]+m[3][0]]
    for line in lines:
        if check(line,'X'):
            print ('X won')
            return
        if check(line,'O'):
            print ('O won')
            return
    if '.' in ''.join(m):
        print ("Game has not completed")
    else:
        print ("Draw")

if __name__=="__main__":
    T = int(input())
    for t in range(1,T+1):
        print("Case #%d:"%t,end=' ')
        solve()
