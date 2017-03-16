# https://code.google.com/codejam/contest/1460488/dashboard#s=p1
# 21 = 7 + 7 + 7, 8 + 7 + 6
# 21 / 3 = 7
# 20 = 7 + 7 + 6, 8 + 6 + 6
# 19 = 7 + 6 + 6
# 18 = 6 + 6 + 6, 7 + 6 + 5
# 17 = 6 + 6 + 5, 7 + 5 + 5
# 5 = 2 + 2 + 1, 3 + 1 + 1 <> 5 % 3 = 2
# 4 = 2 + 1 + 1
# 3 = 1 + 1 + 1, 2 + 1 + 0
# 2 = 1 + 1 + 0, 2 + 0 + 0
# 1 = 1 + 0 + 0
# 0 = 0 + 0 + 0
import sys

def readline():
    return sys.stdin.readline().rstrip()

t = int(readline())
for x in range(t):
    line = readline()
    nums = [int(i) for i in line.split()]
    n = nums[0]
    s = nums[1]
    p = nums[2]
    nums = nums[3:]
    clearly = 0
    borderline = 0
    for num in nums:
        if num % 3 == 0:
            if num / 3 >= p:
                clearly += 1
            elif num > p and num / 3 + 1 >= p:
                borderline += 1
        elif num % 3 == 1:
            if (num+2) / 3 >= p:
                clearly += 1
        else: # num % 3 == 2
            if (num+1) / 3 >= p:
                clearly += 1
            elif (num+1) / 3 + 1 >= p:
                borderline += 1
    count = clearly + min(s, borderline)
    print 'Case #{}: {}'.format(x+1, count)

