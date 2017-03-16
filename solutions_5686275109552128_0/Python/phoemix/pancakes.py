######################################
# Author: Rodrigo Martins Racanicci  #
# E-mail: diguo.m@gmail.com          #
######################################
# - University of Sao Paulo          #
# - University of Hull               #
######################################

T = int(raw_input())


for case in range(T):
    d = int(raw_input())
    pi = map(int, raw_input().split())
    max_time = max(pi)
    min_time = max_time

    # min_p - maximum number of pancakes per person
    for min_p in range(1, max_time + 1):
        spent_time = min_p
        for p in pi:
            if (p > min_p):
                nsplits = p/min_p
                spent_time += (nsplits - 1 if p%min_p == 0 else nsplits)
        min_time = min(min_time, spent_time)

    print "Case #%d: %d" %(case+1, min_time)
