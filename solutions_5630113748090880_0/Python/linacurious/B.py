attempt_list = ['B-test','B-small-attempt0','B-large']
attempt = attempt_list[1]

import time
time.clock()

def solve(heights):
    heights_result = []
    heights_set = list(set(heights))
    for i in heights_set:
        if heights.count(i)%2 == 1:
            heights_result.append(i)
    heights_result.sort()
    return ' '.join(str(x) for x in heights_result)


def main():
    fin = open(attempt + '.in', 'r')
    fout = open(attempt + '.out','w')

    numcases = int(fin.readline())

    for casenum in range(1,numcases+1):
        n = int(fin.readline())
        heights = []
        for i in range(2*n-1):
            heights_row = map(int, fin.readline().split())
            for j in range(n):
                heights.append(next(heights_row))
        fout.write('Case #' + repr(casenum) + ': ' + str(solve(heights)) + '\n')

    fin.close()
    fout.close()

main()
print(time.clock())