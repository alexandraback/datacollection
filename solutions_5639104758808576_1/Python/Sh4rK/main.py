def solve(people):
    total = 0
    needed = 0
    for level, num in enumerate(people):
        if total < level:
            needed += level - total
            total += level - total
        total += int(num)
    return needed


tcnum = int(input())

for tc in range(1, tcnum+1):
    smax, people = input().split()
    print("Case #{}: {}".format(tc, solve(people)))