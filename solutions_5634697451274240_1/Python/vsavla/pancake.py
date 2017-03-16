t = int(input())

for i in range(1, t+1):
    pan_str = input()
    pan_bool = [item == '+' for item in list(pan_str)]
    count = 0

    for j in range(1, len(pan_bool)):
        if pan_bool[0] != pan_bool[j]:
            pan_bool[0] = not pan_bool[0]
            count += 1
    if not pan_bool[0]:
        count += 1
    print("Case #%d: %d" % (i, count))
