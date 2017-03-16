import sys


def solveBig(a, b, k):
    hits = 0
    smaller_machine = min(a, b)
    bigger_machine = max(a, b)
    smaller = min(smaller_machine, k)
    hits = smaller*bigger_machine
    for i in range(smaller, smaller_machine):
        hits += smaller
        for j in range(smaller, bigger_machine):
            if i & j < k:
                hits += 1
    return hits
"""
def solveBig(a, b, k):
    hits = 0
    smaller_machine = min(a, b)
    bigger_machine = max(a, b)
    smaller = min(smaller_machine, k)
    hits = smaller*bigger_machine
    for i in range(smaller, smaller_machine):
        #for j in range(0, bigger_machine):
        hits += smaller
        for j in range(smaller, bigger_machine):
            if i & j < k:
                hits += 1
    return hits
"""

def solve(a, b, k):
    hits = 0
    for i in range(a):
        for j in range(b):
            if i & j < k:
                hits += 1
    return hits

if __name__ == '__main__':
    in_file = sys.argv[1]
    f = open(in_file, 'r')
    cases = int(f.readline())
    for i in range(cases):
        nums = list(map(int, f.readline().split()))
        print('Case #{0}: {1}'.format(i+1, solveBig(nums[0], nums[1], nums[2])))
    f.close()