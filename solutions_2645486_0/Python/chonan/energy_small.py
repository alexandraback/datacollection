#! /usr/bin/env python3
# -*- coding: utf8 -*-
# vim: expandtab ts=4 ai

#from functools import reduce

def do_calc(stat):
    (score,e,r,task,hp) = stat
    if len(task) == 1:
        return score + task[0] * hp

#    print(hp,len(task),task)

    max_value = 0
    for h in range(hp,-1,-1):
        next_hp = min(e,hp-h+r)
        next_stat = [score+(h*task[0]),e,r,task[1:],next_hp]
#        print(next_stat)
        max_value = max(max_value,do_calc(next_stat))

    return max_value

def main():
    for c in range(int(input())):
        pattern = []
        (e,r,n) = map(int,input().split())

        v = list(map(int,input().split()))

        # SCORE,E,R,[V],HP
        judge = do_calc([0,e,r,v,e])
     
        print('Case #%d: %s' % ( c+1, judge ))

if __name__ == '__main__':
    main()
