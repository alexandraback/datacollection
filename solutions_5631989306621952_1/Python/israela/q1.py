import sys

def solve(s):
    res = [s[0]]
    for i in xrange(1,len(s)):
        if s[i] >= res[0]:
            res.insert(0,s[i])
        else:
            res.append(s[i])
    return "".join(res)

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