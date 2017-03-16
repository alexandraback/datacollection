def check(str):
    flag = True
    for base in range(2, 11):
        if int(str, base) % (base + 1) != 0:
            flag = False
            break
    return flag


t = int(input())  # read a line with a single integer

print("Case #1:")
for i in range(1, t + 1):
    # read a list of integers, 2 in this case
    n, j = [int(s) for s in input().split(" ")]

    start_number = pow(10, n - 1) + 1
    increase = 2
    index = 0
    counter = 0

    while counter < j:
        str_num = "{0:b}".format(int(str(start_number), 2) + index * increase)
        if check(str_num):
            print("{} 3 4 5 6 7 8 9 10 11".format(str_num))
            counter += 1
        index += 1
