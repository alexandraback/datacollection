T = int(input())

for t in range(T):
    maxshyness, shyness_str = input().strip().split()

    shyness = map(int, shyness_str)

    standing = 0
    friends = 0

    for i, n in enumerate(shyness):
        f = max(0, i - standing)
        friends += f
        standing += f + n

    print("Case #" + str(t+1) + ": " + str(friends))
            



