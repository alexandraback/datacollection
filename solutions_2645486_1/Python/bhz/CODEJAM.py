from time import time
from math import ceil, sqrt, floor

startTime = time()
def expTime(pct): print int(pct * 100), "{0:.3f}".format((time() - startTime) * (1-pct) / pct)

def calc(start, _max, regain, act_list, finish):
    if len(act_list) == 0: return 0
    # recursive case
    maxi = act_list.index(max(act_list))
    left = act_list[:maxi]
    right = act_list[maxi+1:]
    if (len(act_list) - maxi - 1) * regain >= finish:
        if start + maxi * regain >= _max: return calc(start, _max, regain, left, _max) + max(act_list) * _max + calc(regain, _max, regain, right, finish)
        else: return calc(start, _max, regain, left, start + maxi * regain) + max(act_list) * (start + maxi * regain) + calc(regain, _max, regain, right, finish)
    else:
        R = finish - (len(right) + 1) * regain
        S = start + maxi * regain
        if S >= _max: return calc(start, _max, regain, left, _max) + max(act_list) * (_max - R) + calc(R + regain, _max, regain, right, finish)
        else: return calc(start, _max, regain, left, S) + max(act_list) * (S - R) + calc(R + regain, _max, regain, right, finish)
        
    

with open('DATA.TXT') as in_file:
    # get cases
    in_arr = in_file.read().split('\n')
    num_cases = int(in_arr[0])
    case_arr = []
    row = 1
    for e in range(num_cases):
        # process txt
        case_len = 2
        case_arr.append(in_arr[row:row+case_len])
        row += case_len
        

# initialize
out = []
num = 0
for case in case_arr:
    if num % (num_cases / 10 + 1) == 1: expTime(float(num)/num_cases)
    res = 0
    # process case
    E = int(case[0].split(' ')[0])
    R = int(case[0].split(' ')[1])
    act_list = [int(i) for i in case[1].split(' ')]
    res = calc(E, E, R, act_list, 0)
    # output
    num += 1
    out.append('Case #' + str(num) + ': ' + str(res))

# output
with open('OUT.txt', 'w') as f:
    for e in out:
        f.write(str(e) + '\n')
