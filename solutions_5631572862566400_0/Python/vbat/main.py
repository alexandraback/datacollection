from itertools import tee, izip
from collections import defaultdict

importResults = list()

while True:
    try:
        text = raw_input()
        if len(text.strip()) == 0:
            break
        else:
            importResults.append(text.strip())
    except EOFError:
        break

def processCase(data):
    lines = dict()
    cycles = dict()
    for i in range(1, len(data)+1):
        candidate = [i]
        next_bff = data[candidate[-1]-1]
        while next_bff not in candidate:
            candidate.append(next_bff)
            next_bff = data[candidate[-1]-1]
        # print candidate
        if next_bff == candidate[0]:
            cycles[i] = candidate
        elif next_bff == candidate[-2]:
            lines[i] = candidate
    line_tail = dict()
    for line in dict.itervalues(lines):
        a = line[-2]
        b = line[-1]
        k = (min(a, b), max(a, b))
        count = line_tail.setdefault(k, [0, 0])
        if a < b:
            count[0] = max(count[0], len(line))
        else:
            count[1] = max(count[1], len(line))
        # line_tail.setdefault(k, []).append(line)

        # line_tail[] = line_tail.get(k, []) + [line]

    longest_joined_tail = 0
    for count in dict.itervalues(line_tail):
        longest_joined_tail = max(longest_joined_tail, sum(count)-2) #subtract 2 for the overlap
    longest_line = 0
    for line in dict.itervalues(lines):
        longest_line = max(longest_line, len(line))
    longest_cycle = 0
    for cycle in dict.itervalues(cycles):
        longest_cycle = max(longest_cycle, len(cycle))

    # print line_tail
    # print lines
    # print cycles
    return max(longest_cycle, longest_joined_tail, longest_line)

preprocessedImport = []

for i in range(len(importResults)):
    if i==0:
        pass
    else:
        if i%2 ==0:
            thisCase = map(int, importResults[i].split())
            preprocessedImport.append(thisCase)

# print preprocessedImport

for i in range(len(preprocessedImport)):
    print "Case #{case_id}: {result}".format(case_id = i+1, result = processCase(preprocessedImport[i]))



