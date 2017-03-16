import sys
from collections import deque
import itertools
import math

def solve(*args, **kwargs):
    n = scanf_int()
    diag = {}
    for i in range(1, n+1):
        l = scanf_list_int()
        diag[i] = l[1:]

    for cs in diag:
        visited = set([cs])
        S = deque([cs])
        while S:
            elem = S.popleft()
            for ngb in diag[elem]:
                if ngb in visited:
                    return 'Yes'
                else:
                    S.append(ngb)
                    visited.add(ngb)
    return 'No'


def Main():
    tests = scanf_int() 
    for tc in range(1, tests + 1):
        print("Case #{}: {}".format(tc, solve()))

def scanf_list_str():
    return sys.stdin.readline().strip().split()

def scanf_list_int():
    return map(int, scanf_list_str())

def scanf_list_float():
    return map(float, scanf_list_str())

def scanf_str():
    return scanf_list_str()[0]

def scanf_int():
    return scanf_list_int()[0]

def scanf_float():
    return scanf_list_float()[0]

if __name__ == '__main__':
    Main()
