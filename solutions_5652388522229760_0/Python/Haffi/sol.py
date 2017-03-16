import fileinput

data = fileinput.input()
T = int(data[0])

for i in range(1,T+1):
    num = int(data[i])
    seen = [0 for _ in range(10)]
    idx = 1
    tmp = 0
    while (not all(seen)) and num != 0:
        tmp = idx*num
        tmp2 = tmp
        while tmp2 > 0:
            last_digit = tmp2%10
            seen[last_digit] += 1
            tmp2 /= 10
        idx += 1
    if all(seen):
        print("Case #{}: {}".format(i,tmp))
    else:
        print("Case #{}: INSOMNIA".format(i))


