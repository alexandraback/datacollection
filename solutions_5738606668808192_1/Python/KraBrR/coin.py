#!/usr/bin/env python
import math
import itertools

def custom_range(start, stop, step):
    while start < stop:
        yield start
        start += step

def is_prime(x):
    if x == 2:
        return True
    if x < 2 or x % 2 == 0:
        return False
    return all(x % i for i in custom_range(3, int(math.sqrt(x)-1), 2))

def is_maybe_prime(x):
    if x == 2:
        return True
    if x < 2 or x % 2 == 0:
        return False
    return all(x % i for i in custom_range(3, min(x, 1000), 2))

def get_divisor(x):
    for i in iter(itertools.count(2).next, x):
        if x % i == 0:
            return str(i)

    # should not happen
    return str(x)

inp = open("C-large.in.txt", 'r')
out = open("large_output.txt", 'w')

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
            x = long(base_jam, j)
            # if is_prime(x):
            if is_maybe_prime(x):
                prime = True
                break
            else:
                base_num.append(get_divisor(x))
        if not prime:
            result = base_jam + " " + " ".join(base_num)
            out.write(result + '\n')
            count = count - 1
        if count <= 0:
            break

inp.close()
out.close()
