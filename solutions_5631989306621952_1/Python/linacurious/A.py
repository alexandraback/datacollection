attempt_list = ['A-test','A-small-attempt0','A-large']
attempt = attempt_list[2]

import time
time.clock()

def solve(s):
    s_original = list(s)
    s_result = [s_original[0]]
    if len(s_original) > 1:
        s_original = s_original[1:]
        for letter in s_original:
            if letter >= s_result[0]:
                s_result.reverse()
                s_result.append(letter)
                s_result.reverse()
            else:
                s_result.append(letter)
    return ''.join(s_result)



def main():
    fin = open(attempt + '.in', 'r')
    fout = open(attempt + '.out','w')

    numcases = int(fin.readline())

    for casenum in range(1,numcases+1):
        s = fin.readline()
        fout.write('Case #' + repr(casenum) + ': ' + str(solve(s)))

    fin.close()
    fout.close()

main()
print(time.clock())