import math


for t in range(int(input())):
    R, C, W = [int(x) for x in input().split()]
    print('Case #{0}: {1}'.format(t + 1, int(math.ceil(C/W)) + W - 1))
