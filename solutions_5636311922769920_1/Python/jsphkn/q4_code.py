f = open('D-large.in', 'r')
fo = open('out_code4_large.out', 'w')

import math

def give_positions(k, c, s):
    if s < math.ceil(float(k)/c):
        return "IMPOSSIBLE"
    index = 0
    return_list = []
    while index < k:
        position = 1
        for i in xrange(c):
            remainder = index % k
            position += k**i * remainder
            index += 1
        return_list.append(position)
    return return_list

def convert_list_to_string(return_list):
    if return_list == "IMPOSSIBLE":
        return return_list
    return_string = ''
    for i in xrange(len(return_list)):
        return_string = return_string + str(return_list[i])
        if i != len(return_list)-1:
            return_string = return_string + " "
    return return_string

a = int(f.readline())
overall = []
for i in xrange(a):
    b = f.readline().strip().split(" ")
    c = convert_list_to_string(give_positions(int(b[0]), int(b[1]), int(b[2])))
    overall.append(c)
    print c

for i in xrange(1, a+1):
    output = "Case #" + str(i) + ": " + overall[i-1]
    fo.write(output)
    fo.write('\n')
