import sys

def solve(n):
    if n == 1: return 1
    last = [1]
    nums = {1}
    for _ in range(100000):
        new = []
        for i in last:
            k = int(str(i)[::-1])
            if i+1 == n or k == n:
                return _+2

            if i+1 not in nums:
                new.append(i+1)
                nums.add(i+1)

            if k not in nums:
                new.append(k)
                nums.add(k)
        last = new

for i in range(int(input())):
    n = int(input())
    print(i, file=sys.stderr)
    print('Case #{0}: {1}'.format(i+1, solve(n)))
