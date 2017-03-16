import math
from numpy import array
from sys import stdin

def read_input():
    T = int(stdin.readline())
    cases = list()
    for t in range(T):
        N,M = [int(x) for x in stdin.readline().split()]
        c = {'N': int(N), 'M': int(M)}
        lawn = list()
        for n in range(N):
            lawn.append([int(a) for a in stdin.readline().split()])
        c['A'] = array(lawn)
        cases.append(c)
    return cases

case = 1
def output_case(outcome):
    global case
    print 'Case #%d: %s' % (case, outcome)
    case += 1
    
def check_case(c):
    A = c['A']
    cmax = A.max(0)
    rmax = A.max(1)
    for ir in range(c['N']):
        for ic in range(c['M']):
            h = A[ir][ic]
            if not (h >= rmax[ir] or h >= cmax[ic]):
                return False
    return True
    

cases = read_input()
for c in cases:
    output_case('YES' if check_case(c) else 'NO')
