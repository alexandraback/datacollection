from time import time
from math import ceil, sqrt, floor
from decimal import *

startTime = time()
def expTime(pct): print int(pct * 100), "{0:.3f}".format((time() - startTime) * (1-pct) / pct)

with open('DATA.TXT') as in_file:
    # get cases
    in_arr = in_file.read().split('\n')
    num_cases = int(in_arr[0])
    case_arr = []
    row = 1
    for e in range(num_cases):
        # process txt
        case_len = 1
        case_arr.append(in_arr[row:row+case_len])
        row += case_len
        

# initialize
out = []
num = 0
for case in case_arr:
    if num % (num_cases / 10 + 1) == 1: expTime(float(num)/num_cases)
    res = 0
    # process case
    r = int(case[0].split(" ")[0])
    t = int(case[0].split(" ")[1])
    getcontext().prec = 50
    A = 2
    B = 2*r+3
    C = 2*r+1-t
    res = int(floor((-Decimal(B)+Decimal(B**2-4*A*C).sqrt())/(Decimal(2*A))+1))
    # output
    num += 1
    out.append('Case #' + str(num) + ': ' + str(res))
    pass

# output
with open('OUT.txt', 'w') as f:
    for e in out:
        f.write(str(e) + '\n')
