#!/usr/bin/env python

from sys import argv

script, filename = argv

def get_cycle_length(i, bffs):
    num_seen = 1
    cur = i
    already_seen = { i: 1 }
    while True:
        cur = bffs[cur]
        if cur == i:
            return num_seen
        num_seen += 1
        if cur in already_seen:
            return 0
        already_seen[cur] = 1

def get_lasso_length(i, bffs):
    num_seen = 2
    prev = i
    cur = bffs[prev]
    already_seen = { prev: 1, cur: 1 }
    while True:
        upcoming = bffs[cur]
        # print "prev, cur, upcoming: {}, {}, {}".format(prev, cur, upcoming)
        if upcoming == prev:
            # print "returning [{}, {}, {}]".format(num_seen, prev, cur)
            return [num_seen, prev, cur]

        num_seen += 1
        if upcoming in already_seen:
            return [0, 0, 0]
        already_seen[cur] = 1
        prev = cur
        cur = upcoming

with open(filename, 'r') as f:
    number_of_cases = int(f.readline().rstrip('\n'))
    case_number = 0
    while case_number < number_of_cases:
        case_number += 1
        num_kids = int(f.readline().rstrip('\n'))
        line = f.readline().rstrip('\n')
        bffs = line.split(' ')
        bffs.insert(0, 0)
        for i in range(1, num_kids + 1):
            bffs[i] = int(bffs[i])
        
        longest_cycle = 0
        lasso_length = [[0, 0, 0]]
        for i in range(1, num_kids + 1):
            cycle_answer = get_cycle_length(i, bffs)
            longest_cycle = max(cycle_answer, longest_cycle)
            # print "cycle {} is {}".format(i, cycle_answer)
            if cycle_answer == 2:
                lasso_length.append([2, i, bffs[i]])
                # print "lasso_length {} is {}".format(i, lasso_length[i])
            elif cycle_answer > 0:
                lasso_length.append([0, 0, 0])
            else:
                lasso_length.append(get_lasso_length(i, bffs))
                # print "lasso_length {} is {}".format(i, lasso_length[i])

        farthest_away = [[0, 0]]
        # print "lasso_length is {}".format(lasso_length)
        for i in range(1, num_kids + 1):
            farthest_away.append([0, 0])
            max_seen = 0
            if lasso_length[i][0] > 0:
                for j in range(1, num_kids + 1):
                    j_length = lasso_length[j][0]
                    if (j_length > max_seen and lasso_length[j][1] == lasso_length[i][2]):
                        # print "marking {} as the farthest away from {}".format(j, i)
                        max_seen = j_length
                        farthest_away[i] = [j, j_length]

        # print "farthest_away is {}".format(farthest_away)
        lasso_total = 0 
        for i in range(0, num_kids):
            j = farthest_away[i][0]
            if j > i and i == farthest_away[j][0]:
                lasso_total += lasso_length[i][0] + lasso_length[j][0] - 2
                # print "adding a chain of kids from {} to {}".format(i, j)

        # print "lasso_total is {}".format(lasso_total)
        answer = max(lasso_total, longest_cycle)
        print "Case #{}: {}".format(case_number, answer)
