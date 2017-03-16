from time import time
from math import ceil, sqrt, floor
from itertools import combinations_with_replacement as comb
from operator import mul

startTime = time()
def expTime(pct): print int(pct * 100), "{0:.3f}".format((time() - startTime) * (1-pct) / pct)

def prod(iterable): return reduce(mul, iterable, 1)
    
with open('DATA.TXT') as in_file:
    # get cases
    in_arr = in_file.read().split('\n')
    num_cases = int(in_arr[1].split(' ')[0])
    M = int(in_arr[1].split(' ')[2])
    K = int(in_arr[1].split(' ')[1])
    case_arr = []
    row = 2
    for e in range(num_cases):
        # process txt
        case_len = 1
        case_arr.append(in_arr[row:row+case_len])
        row += case_len

def intersect(a, b): return list(set(a) & set(b))
        

# initialize
out = ['Case #1:']
num = 0
for case in case_arr:
    if num % (num_cases / 10 + 1) == 1: expTime(float(num)/num_cases)
    res = ''
    # process case
    intcase = list(reversed(sorted(int(i) for i in case[0].split(' '))))
    cur = []
    for e in intcase:
        this = []
        possible = comb(range(1, M+1), K)
        for t in possible:
            L = list(t)
            if prod(L) == e:
                num1 = L.count(1)
                for rep in range(num1): L.remove(1)
                for k in comb(range(2, M+1), num1): this.append(sorted(L + list(k)))
        if cur == []: cur = this[:]
        else: cur = intersect([tuple(i) for i in cur], [tuple(i) for i in this])
    for i in cur[0]: res += str(i) 
    # output
    num += 1
    #out.append('Case #' + str(num) + ': ' + str(res))
    out.append(str(res))

# output
with open('OUT.txt', 'w') as f:
    for e in out:
        f.write(str(e) + '\n')
