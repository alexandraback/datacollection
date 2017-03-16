t = int(input())

for i in range(1, t+1):
    pan_str = input()
    pan_bool = [item == '+' for item in list(pan_str)]
    count = 0
    while pan_bool.count(False) != 0:
        if (not pan_bool[0]) in pan_bool:
            a = pan_bool.index(not pan_bool[0])
        else:
            count += 1
            break
        for k in range(0, a):
            pan_bool[k] = not pan_bool[k]
        count += 1
    print("Case #%d: %d" % (i, count))
    