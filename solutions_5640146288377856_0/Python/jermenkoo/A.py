from math import ceil

T = int(input())

# small
for i in range(T):
    R, C, W = map(int, input().split())
    print("Case #{}:".format(i + 1), ceil(R * C / W) + (W - 1))
