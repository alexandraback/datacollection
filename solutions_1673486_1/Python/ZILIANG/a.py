
T = input()


for t in range(T):
    A, B = map(int, raw_input().split())

    prob = map(float, raw_input().split())

    giveup = 1 + B + 1
    ret = giveup

    for i in range(1, len(prob)):
        prob[i] *= prob[i-1]

    for start in range(A-1, -1, -1):
        p = prob[start]

        rest_len = B - 1 - start;
        del_len = A - 1 - start
        enter = 1
        ans = del_len + p * (rest_len + enter) + (1-p) * (rest_len + enter + B + enter)

        if ans < ret:
            ret = ans

    print 'Case #%d: %f' % (t+1, ret)
