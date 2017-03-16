from math import ceil

t = input()
for poo in range(t):
    d = input()
    s = map(int, raw_input().split())

    min1 = 1000
    for height in range(1, 1001):
        time = 0
        for i in s:
            time += ceil(i*1.0 / height) - 1
        min1 = min(time + height, min1)

    print "Case #" + str(poo+1) + ": " + str(int(min1))
