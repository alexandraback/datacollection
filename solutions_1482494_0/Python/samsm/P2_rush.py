#!/usr/bin/python

import sys
import os
import re

def stat2str(stat):
    return ''.join(['%d%d'%(v[0],v[1]) for v in stat])

def statcopy(stat):
    return [v[:] for v in stat]

def search_ex(stardict, cost):
    dict = {}

    for star, st in stardict.values():
        #print 'info', star, st
        for lv in range(len(st)):
            # star1
            if st[lv][0] == 0 and cost[lv][0] <= star:
                new_st = statcopy(st)
                new_st[lv][0] = 1
                new_star = star + 1
                new_flag = stat2str(new_st)
                if new_flag not in dict:
                    dict[new_flag] = [new_star, new_st] 

            # star
            if st[lv][1] == 0 and cost[lv][1] <= star:
                new_st = statcopy(st)
                new_st[lv][1] = 1
                if st[lv][0] == 0:
                    new_star = star + 3
                else:
                    new_star = star + 2
                new_flag = stat2str(new_st)
                if new_flag not in dict:
                    dict[new_flag] = [new_star, new_st] 
                else:
                    if new_star > dict[new_flag][0]: 
                        dict[new_flag][0] = new_star
    return dict

def search(lv, cost):
    stat = [[0,0] for n in range(lv)]
    flag = stat2str(stat)
    dict = {}
    dict[flag] = [0, stat] 
    step = 0

    while True:
        dict = search_ex(dict, cost)
        #print 'info', dict.values()
        step += 1

        # check
        if len(dict.keys()) == 0:
            return -1

        for star, st in dict.values():
            if lv == sum([st[v][1] for v in range(lv)]):
                return step
    return -1

def load_input(filename):
    f = open(filename, 'r')
    N = int(f.readline())
    list = []
    for i in range(N):
        lv = int(f.readline())
        cost = []
        for n in range(lv):
            array = map(int, f.readline().split())
            cost.append(array[0:2])
        list.append( [lv, cost])
    return list


def main():
    #infile = 'B-test.in'
    #outfile = 'B-test.out'
    infile = 'B-small-attempt0.in'
    outfile = 'B-small-attempt0.out'
    #infile = 'B-large.in'
    #outfile = 'B-large.out'

    list = load_input(infile)
    fid = open(outfile, 'w')

    #for a in list:
        #print a[0]
        #print stat2str(a[1])
        #print 'result'
        #print search(a[0], a[1])


    for n in range(len(list)):
        print n
        lv, cost = list[n]
        result = search(lv, cost)
        if result > 0:
            print >> fid, 'Case #%d: %d' % (n+1, result)
        else:
            print >> fid, 'Case #%d: Too Bad' % (n+1)
#
#        result = run(a, b, array) 
#        print >> fid, 'Case #%d: %f' % (n+1, result)

if __name__ == '__main__':
    main()
