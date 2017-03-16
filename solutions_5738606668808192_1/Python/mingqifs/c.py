T = int(input())
for case in range(1, T + 1):
    param = input().split()
    N = int(param[0])
    J = int(param[1])

    l = (N - 2) // 2

    ans_list = []

    for i in range(l):
        for j in range(i):
            res = []
            for k in range(l):
                if k == i or k == j:
                    res.append('1')
                else:
                    res.append('0')

            ans_list.append(res)

    print("Case #{0}:".format(case))
    cnt = 0
    for i in ans_list:
        for j in ans_list:
            cnt += 1
            if cnt > J:
                exit()

            res = [0] * 2 * l
            res[::2] = i
            res[1::2] = j
            print('1{0}1 3 2 3 2 7 2 3 2 3'.format(''.join(res)))

