num_case = int(input())
for case_t in range(1, num_case+1):
    Input = [int(i) for i in input().split(" ")]
    B, M = Input
    if M > 2**(B-2):
        print("Case #%d: IMPOSSIBLE"%(case_t))
        continue
    else:
        print("Case #%d: POSSIBLE"%(case_t))

    v = [[0]]
    tmp_M = M
    if M == 2**(B-2):
        tmp_v = [1 for i in range(B-1)]
        v[0] = [0] + tmp_v
    else:
        for i in range(1, B-1):
            if tmp_M & 1: v[0].append(1)
            else: v[0].append(0)
            tmp_M >>= 1
        v[0].append(0)

    for i in range(1, B-1):
        next_v = [1 if x < i+1 else 0 for x in range(2, B)]
        next_v = [0] + next_v + [1]
        v.append(next_v)
    v.append([0 for i in range(B)])

    res = "\n".join(["".join([str(x) for x in row]) for row in v])
    print(res)

    #print("Case #%d: %s"%(case_t, ANS))


