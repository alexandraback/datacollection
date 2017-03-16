from __future__ import division
from math import ceil
from math import floor
from itertools import product
from copy import copy
from sys import argv

def solve(l):
    # print l
    # if all the elements of hte l in less than 3 return the largest value
    l.sort(reverse=True)
    if max(l) <= 3:
        return max(l)

    if len(l) <= 1:
        # if l[0] <=3:
            # return l[0]
        # else:[int(ceil(l[0
        # print [int(ceil(l[0]/2)), int(floor(l[0]/2))]
        return 1 + solve([int(ceil(l[0]/2)), int(floor(l[0]/2))])
    
    remaining_time = solve(l[1:])
    # decide if special minute or no special minute
    # time_without = remaining_time + max(0, l[0] - remaining_time)
    time_without = l[0]
    new_list = []
    new_list.extend(l[1:])
    new_list.append(int(ceil(l[0]/2)))
    new_list.append(int(floor(l[0]/2)))
    new_list.sort(reverse=True)
    time_with = 1 + solve(new_list)
    # time_with = 1 + solve(sorted(new_list, reverse=True))

    # print time_with, time_without, min(time_with, time_without) 
    return min(time_with, time_without) 

def finish_eating(l):
    return max(l) == 0

def second_alternate(l):
    sol = max(l)
    for i in xrange(1, max(l)+1):
        # best to iterate every combination , slow but atleast works for the smalelr dataset
        time_count = i + sum([int(ceil(diner/i)) -1 for diner in l if diner > i])
        # for diner in l:
            # if diner > i:
                # time_count += int(ceil(diner/i)) -1
        sol = min(sol, time_count)
    return sol

def alternate(l):
    # pass
    # l.sort(reverse=True)
    ml = max(l)
    sol_list = []
    # for p in xrange(ml):
    #     # reduce the list 
    #     diners = copy(l)
    #     diners = map(lambda d: d-p, diners)
    #     sol = p
    #     if finish_eating(diners):
    #         sol_list.append(sol)
    #         break
    #     diners = filter(lambda drem: drem > 0, diners)
    #     sol += solve(diners)
    #     sol_list.append(sol)
    # print min(sol_list), solve(l)



    for p in product([0,1], repeat=ml):
        time_count = 0
        diners = copy(l)
        tot_break = 0
        for i in p:
            if finish_eating(diners): break
            if not i:
                time_count += 1 # eat one time
                diners = map(lambda d: d-1, diners)
                if finish_eating(diners): break
                # otherwise reduce
                diners = filter(lambda drem: drem > 0, diners)
            else:
                # special minute
                time_count += 1
                diners.sort(reverse=True)
                new_list = []
                new_list.extend(diners[1:])
                new_list.append(int(ceil(diners[0]/2)))
                new_list.append(int(floor(diners[0]/2)))
                new_list.sort(reverse=True)
                diners = copy(new_list)
        sol_list.append(time_count)

# print solve([9,9,9])
# alternate([1,2,3])
# alternate([5,2,3])
# print solve([5,2,3])

def main():
    filename = 'Binput.in'
    if len(argv) > 1:
        filename = argv[1]

    with open(filename) as f:
        T = int( f.readline() )
        case_count = 0
        for i in xrange(T):
            case_count += 1
            d = f.readline().rstrip('\n')
            l = f.readline().rstrip('\n')
            lin = map(int, l.split(' '))
            # print d, len(lin), lin,
            # alternate(lin)
            # ans = solve(sorted(lin, reverse=True))
            ans = second_alternate(lin)
            # print "Case #" + str(case_count) + ": " + str(ans)
            print "Case #" + str(case_count) + ": " + str(ans)
    
main()
# alternate([1,2,3])
# print second_alternate([9,6])
# ans 4
# print  solve(sorted([2,3,4,2,1], reverse=True))
# print  solve(sorted([2,3,6,2,1], reverse=True))

# ans 3 
# print  solve([3,2])

# ans = 4
# print solve([5,3,2])

# print solve([18])


