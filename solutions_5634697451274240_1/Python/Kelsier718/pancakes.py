t = int(input())
for i in range(1, t + 1):
    s = input()
    #print(s)
    sign = '-'
    count = 0
    for j in s[::-1]:
        if j == sign:
            if sign == '-':
                sign = '+'
            else:
                sign = '-'
            count = count + 1
    print("Case #{}: {}".format(i, count))

