from math import ceil

def do_time(pancakes, mfp):
    operations = mfp
    for pancake in pancakes:
        operations += ceil(pancake / mfp) - 1
    return operations

def case(pancakes):
    max_pancake = max(pancakes)
    best_time = float("inf")
    for max_final_pancake in range(1, max_pancake + 1):
        time = do_time(pancakes, max_final_pancake)
        best_time = min(best_time, time)
    return best_time

n = int(input())
for i in range(n):
    d = int(input())
    inp = list(map(int, input().split()))
    print("Case #{}: {}".format(i + 1, case(inp)))
