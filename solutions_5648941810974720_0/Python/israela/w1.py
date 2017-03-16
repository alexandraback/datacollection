from gettext import find
import sys

def solve(s):
    letters = ["ZERO", "ONE", "TWO", "THREE", "FOUR", "FIVE", "SIX", "SEVEN", "EIGHT", "NINE"]
    res = [0] * 10

    res[0] += s.count('Z')
    res[2] += s.count('W')
    res[4] += s.count('U')
    res[6] += s.count('X')
    res[8] += s.count('G')

    dig1 = [0,2,4,6,8]
    for d in dig1:
        for l in letters[d]:
            s = s.replace(l, '', res[d])

    res[1] += s.count('O')
    res[3] += s.count('H')
    res[5] += s.count('F')
    res[7] += s.count('S')

    dig2 = [1,3,5,7]
    for d in dig2:
        for l in letters[d]:
            s = s.replace(l, '', res[d])

    if len(s) % 4 != 0:
        print "error", s
    res[9] = len(s) / 4

    final_res = ""
    for i in xrange(10):
        for d in xrange(res[i]):
            final_res += str(i)
    return final_res

input_file = open(sys.argv[1], "r")
output_file = open(sys.argv[2], "w")

T = int(input_file.readline().strip())
strings = input_file.readlines()
results = []
for s in strings:
    results.append(solve(s.strip()))

for i in xrange(T):
    output_file.write("Case #{0}: {1}\n".format(i+1, results[i]))

input_file.close()
output_file.close()