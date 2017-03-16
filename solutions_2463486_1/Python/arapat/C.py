
from sys import stdin
from math import sqrt

def is_fsn(k):
    str_k = str(k)
    return str_k == str_k[::-1]


fsn = []
for i in range(1,10**7):
    if is_fsn(i) and is_fsn(i*i):
        fsn.append(i*i)

T = int(stdin.readline())
for loop in range(1, T+1):
    a,b = [int(x) for x in stdin.readline().split()]
    answer = 0
    for x in fsn:
        if x >= a and x <= b:
            answer += 1
        elif x > b:
            break
    print 'Case #' + str(loop) + ': ' + str(answer)
