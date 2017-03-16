#!/usr/bin/env python
import math
import itertools

def is_prime(x):
    return x > 1 and all(x % i for i in itertools.islice(itertools.count(2), int(math.sqrt(x)-1)))

def get_divisor(x):
    for i in xrange(2, x):
        if x % i == 0:
            return str(i)
    # should not happen
    return str(x)

inp = open("C-small-attempt0.in.txt", 'r')
out = open("small_output.txt", 'w')

ncase = int(inp.readline())


for cidx in range(ncase):
    info = inp.readline()
    list_info = info.split()
    n = int(list_info[0])
    j = int(list_info[1])
    count = j

    out.write("Case #" + str(cidx + 1) + ":\n")
    for li in itertools.product(range(2), repeat=(n - 2)):
    # for li in ["00"]:
        base_num = []
        base_jam = '1' + ''.join([str(i) for i in li]) + '1'
        prime = False
        for j in range(2, 11):
            print "j = " + str(j)
            x = long(base_jam, j)
            print "x = " + str(x)
            if is_prime(x):
                prime = True
                break
            else:
                print "not prime"
                base_num.append(get_divisor(x))
                print "yeah"
        if not prime:
            result = base_jam + " " + " ".join(base_num)
            out.write(result + '\n')
            count = count - 1
        if count <= 0:
            break

inp.close()
out.close()
