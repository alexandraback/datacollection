import math
import sys
import re

def solve(jam, pup):
    result = []
    #print('Input: ', jam, pup)

    for j in range(len(jam)):
        if jam[j] != '?' and pup[j] != '?':
            # Case 1: trivial
            if jam[j] != pup[j]:
                if jam[j] > pup[j]:
                    jam = jam.replace('?', '0')
                    pup = pup.replace('?', '9')
                else:
                    jam = jam.replace('?', '9')
                    pup = pup.replace('?', '0')
            # Case 2: do nothing
        else:
            if jam[j] == '?' and pup[j] == '?':
                jam = jam[:j] + '0' + jam[j+1:]
                jam1, pup1 = solve(jam, pup)
                jam = jam[:j] + '1' + jam[j+1:]
                jam2, pup2 = solve(jam, pup)
                abs1 = abs(int(jam1) - int(pup1))
                abs2 = abs(int(jam2) - int(pup2))
                if (abs2 < abs1) or (abs2 == abs1 and int(jam2) < int(jam1)):
                    jam1 = jam2
                    pup1 = pup2
                jam = jam1
                pup = pup1

            # Case 3: jam is unknown
            elif jam[j] == '?':
                jam = jam[:j] + pup[j] + jam[j+1:]
                #jam[j] = pup[j]
                jam1, pup1 = solve(jam, pup)

                if pup[j] > '0':
                    jam = jam[:j] + str(int(pup[j]) - 1) + jam[j+1:]
                    #jam[j] = pup[j] - 1
                    jam2, pup2 = solve(jam, pup)

                    abs1 = abs(int(jam1) - int(pup1))
                    abs2 = abs(int(jam2) - int(pup2))
                    if (abs2 < abs1) or (abs2 == abs1 and int(jam2) < int(jam1)):
                        jam1 = jam2
                        pup1 = pup2

                if pup[j] < '9':
                    jam = jam[:j] + str(int(pup[j]) + 1) + jam[j+1:]
                    #jam[j] = pup[j] - 1
                    jam2, pup2 = solve(jam, pup)

                    abs1 = abs(int(jam1) - int(pup1))
                    abs2 = abs(int(jam2) - int(pup2))
                    if (abs2 < abs1) or (abs2 == abs1 and int(jam2) < int(jam1)):
                        jam1 = jam2
                        pup1 = pup2
                jam = jam1
                pup = pup1
            # Case 4: pup is unknown
            else:
                pup = pup[:j] + jam[j] + pup[j+1:]
                #pup[j] = jam[j]
                jam1, pup1 = solve(jam, pup)

                if jam[j] > '0':
                    pup = pup[:j] + str(int(jam[j]) - 1) + pup[j+1:]
                    #pup[j] = jam[j] - 1
                    jam2, pup2 = solve(jam, pup)

                    abs1 = abs(int(jam1) - int(pup1))
                    abs2 = abs(int(jam2) - int(pup2))
                    if (abs2 < abs1) or (abs2 == abs1 and int(pup2) < int(pup1)):
                        jam1 = jam2
                        pup1 = pup2

                if jam[j] < '9':
                    pup = pup[:j] + str(int(jam[j]) + 1) + pup[j+1:]
                    #pup[j] = jam[j] + 1
                    jam2, pup2 = solve(jam, pup)

                    abs1 = abs(int(jam1) - int(pup1))
                    abs2 = abs(int(jam2) - int(pup2))
                    if (abs2 < abs1) or (abs2 == abs1 and int(pup2) < int(pup1)):
                        jam1 = jam2
                        pup1 = pup2
                jam = jam1
                pup = pup1

        
    #print('Output: ', jam, pup)
    return (jam, pup)

#########################################

input_file = open(sys.argv[1], 'r')
nb_tests = int(input_file.readline())

for i in range(nb_tests):
    raw_line = input_file.readline()
    jam_raw = raw_line.split(' ')[0]
    pup_raw = raw_line.split(' ')[1][0:-1]

    jam, pup = solve(jam_raw, pup_raw)
    print('Case #', i + 1, ': ', jam, ' ', pup, sep='')
