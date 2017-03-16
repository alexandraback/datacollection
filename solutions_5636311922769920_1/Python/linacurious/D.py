attempt_list = ['D-test','D-small-attempt0','D-large']
attempt = attempt_list[2]

import time
time.clock()

import math
import itertools

# calculates which tile should be cleaned
def calculate_tile_no(tile_list, k, power):
    if power == 0:
        return next(tile_list)
    return (k**power)*(next(tile_list)-1) + calculate_tile_no(tile_list, k, power-1)

# k - number of tiles, c - complexity of artwork
# s - students, s_todo - tiles needed to clean
def solve(k, c, s):
    s_todo = math.ceil(k/c)
    if s_todo > s:
        return 'IMPOSSIBLE'
    tile_list = itertools.cycle(range(1,k+1))
    result = list()
    while s_todo != 0:
        result.append(calculate_tile_no(tile_list, k, c-1))
        s_todo -= 1
    return (' '.join(map(str, result)))


def main():
    fin = open(attempt + '.in', 'r')
    fout = open(attempt + '.out','w')

    numcases = int(fin.readline())

    for casenum in range(1,numcases+1):
        k, c, s = map(int, fin.readline().split())
        fout.write('Case #' + repr(casenum) + ': ' + str(solve(k, c, s)) + '\n')

    fin.close()
    fout.close()

main()
print(time.clock())