# total = sum 3 scores
# best result = max of 3 scores
# given total points for each and total count surprising scores, what is max
# googlers with best result of at least p

# Hidden state for each googler: surprising (bool), has max 
#
#
# Googler options:
#
#            | Not surprising | Surprising |
# Max <  p   | ?              | ?          |
# Max >= p   | ?              | ?          |

from collections import defaultdict
from itertools import product

def abs(n):
    if n < 0: 
        return -n
    else:
        return n

        
def add_if_not_less(d, k, v):
    if k not in d or d[k] < v:
        d[k] = v

with open("test_case", "r") as f:
    count = int(f.readline().strip())
    for case in range(1, count + 1):
        line = f.readline().strip()
        split_line = line.split( " ")
        
        n = int(split_line[0]) # number of googlers
        s = int(split_line[1]) # number of surprises
        p = int(split_line[2]) # as above
        googler_points = [int(v) for v in split_line[3:]]
        
        options_for_sum = defaultdict(set)

        for (a,b,c) in product(range(11), range(11), range(11)):
            if abs(a - b) <= 2 and abs(b - c) <= 2 and abs(a - c) <= 2:                
                surprising = int(abs(a - b) == 2 or abs(b - c) == 2 or abs(a - c) == 2)
                bigmax     = int(max(a, b, c) >= p)
                total      = a + b + c
                options_for_sum[total].add((surprising, bigmax))
                
        googler_options_list = [options_for_sum[n] for n in googler_points]       
        
        # dynamic programming
        surprise_count_to_max_bigmax = {0:0}
        
        for googler_options in googler_options_list:
            new_surprise_count_to_max_bigmax = {}
            for supcount, max_bigmax_count in surprise_count_to_max_bigmax.iteritems():
                for s_add, b_add in googler_options:
                    if supcount + s_add <= s:
                        add_if_not_less(new_surprise_count_to_max_bigmax,
                                        supcount + s_add,
                                        max_bigmax_count + b_add)
            surprise_count_to_max_bigmax = new_surprise_count_to_max_bigmax
        
        print "Case #" + str(case) + ": " + str(surprise_count_to_max_bigmax[s])

