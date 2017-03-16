import sys
from collections import Counter

firstline = True
n = 1
in_count = 0
data = []
case = 1

for line in sys.stdin:
    if n == 1:
        pass
    else:
        line = line.strip()
        if (in_count == 0):
            in_count = 2 * int(line) - 1
            data = []
        else:
            in_count -= 1
            data = data + line.split(' ')
            if (in_count == 0):
                cnts =  Counter(data)
                vals = []
                for i, j in cnts.items():
                    if j % 2 == 1:
                        vals.append(int(i))
                vals = sorted(vals)
                vals = [str(i) for i in vals]
                print 'Case #' + str(case) + ': ' + ' '.join(vals)
                case += 1
    n += 1
