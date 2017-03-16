import sys


def solve(a, b, k):
    hits = 0
    for i in range(a):
        for j in range(b):
            hits += 1 if i & j < k else 0
    return hits

if __name__ == '__main__':
    in_file = sys.argv[1]
    f = open(in_file, 'r')
    cases = int(f.readline())
    for i in range(cases):
        nums = list(map(int, f.readline().split()))
        print('Case #{0}: {1}'.format(i+1, solve(nums[0], nums[1], nums[2])))
    f.close()