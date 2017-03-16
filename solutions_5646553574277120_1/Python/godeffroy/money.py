#!/usr/bin/python

import sys

def solve_case():
    (C,D,V)=[int(n) for n in sys.stdin.readline().split(" ")]
    coins=sorted([int(n) for n in sys.stdin.readline().split(" ")])
    #print C
    #print D
    #print V
    #print coins
    new_coins_count=0
    if(coins[0]!=1): 
        new_coins_count=new_coins_count+1
    else:
        coins.pop(0)
    max_v=C
    #print max_v

    while True:
        while len(coins) and coins[0]<=max_v+1:
            max_v=max_v+C*coins[0]
            coins.pop(0)
            #print max_v
        if max_v>=V:
            return `new_coins_count`
        max_v=max_v+C*(max_v+1)
        new_coins_count=new_coins_count+1
        #print max_v


cases_count=int(sys.stdin.readline())

for i in xrange(cases_count):
    print "Case #"+`i+1`+": "+solve_case()

