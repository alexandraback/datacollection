from __future__ import division
from itertools import combinations
from sys import argv

def solve(max_shyness, people):
    ans = 0 # stores the number of people required to make the other people stand
    total_people = 0
    for shyness_level, qty_s in enumerate(people):
        qty = int(qty_s)
        if qty == 0: continue
        # print "SNY", shyness_level, qty
        if shyness_level == 0:
            total_people += qty
            continue
        if total_people >= shyness_level:
            total_people += qty
        else:
            # print shyness_level, total_people
            ans += shyness_level - total_people
            total_people = shyness_level + qty

    return ans
    

def main():
    filename = 'input.in'
    if len(argv) > 1:
        filename = argv[1]

    with open(filename) as f:
        T = int( f.readline() )
        case_count = 0
        for i in xrange(T):
            case_count += 1
            l = f.readline().rstrip('\n')
            max_shyness, people = l.split(' ')
            ans = solve(int(max_shyness), people)
            print "Case #" + str(case_count) + ": " + str(ans)
   
main()
# print solve(5, '110011')



