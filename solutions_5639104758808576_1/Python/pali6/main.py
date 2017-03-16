n = int(input())
for i in range(n):
    counts = list(map(int, input().split()[1]))
    total = 0
    required = 0
    for j, count in enumerate(counts):
        required += max(0, j - total)
        total += max(0, j - total)
        total += count
    print("Case #{}: {}".format(i + 1, required))
