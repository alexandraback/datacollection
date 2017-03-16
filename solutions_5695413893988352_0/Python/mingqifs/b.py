import sys
sys.setrecursionlimit(150000000)  # set the maximum depth as 1500


def update():
    global ans_now, final_ans
    if abs(ans_now[0]) < abs(final_ans[0]) or (ans_now[0] == final_ans[0] and ans_now[1][0] < final_ans[1][0]):
        final_ans[0] = ans_now[0]
        final_ans[1] = [x for x in ans_now[1]]

def dfs(l):
    global ans_now
    if l < 0:
        update()
        return
    if x[l] != '?' and y[l] != '?':
        xx = int(x[l])
        yy = int(y[l])
        rng = [0,0]
    elif x[l] == '?' and y[l] == '?':
        rng = [-9, 9]
    elif x[l] == '?':
        yy = int(y[l])
        rng = [-yy, 9 - yy]
    else:
        xx = int(x[l])
        rng = [xx - 9, xx]

    target = -ans_now[0] // d[l]
    target = [target, target + 1]
    target = [max(min(ii, rng[1]), rng[0]) for ii in target]
    if target[0] == target[1]:
        target = [target[0]]

    for tx in target:
        if x[l] == '?' and y[l] == '?':
            if tx >= 0:
                xx = tx
                yy = 0
            else:
                xx = 0
                yy = -tx
        elif x[l] == '?':
            xx = yy + tx
        elif y[l] == '?':
            yy = xx - tx
        ans_now[1][0] += str(xx)
        ans_now[1][1] += str(yy)
        ans_now[0] += tx * d[l]
        dfs(l-1)
        ans_now[0] -= tx * d[l]
        ans_now[1][0] = ans_now[1][0][:len(ans_now[1][0]) - 1]
        ans_now[1][1] = ans_now[1][1][:len(ans_now[1][1]) - 1]

T = int(input())
d = [10**i for i in range(18)]
for case in range(1, T + 1):
    print(case, file=sys.stderr)
    line = input()
    t = line.split()
    x = t[0][::-1]
    y = t[1][::-1]
    length = len(x)
    final_ans = [0, ['', '']]

    for j in range(length):
        i = length - 1 - j
        if x[i] != '?' and y[i] != '?':
            final_ans[0] += d[i] * (int(x[i]) - int(y[i]))
            final_ans[1][0] += x[i]
            final_ans[1][1] += y[i]
        elif x[i] == '?' and y[i] == '?':
            final_ans[1][0] += '0'
            final_ans[1][1] += '0'
        elif x[i] =='?':
            final_ans[1][0] += y[i]
            final_ans[1][1] += y[i]
        else:
            final_ans[1][0] += x[i]
            final_ans[1][1] += x[i]
    final_ans[1] = [x for x in final_ans[1]]

    ans_now = [final_ans[0], ['','']]
    dfs(length - 1)
    print("Case #{0}: {1} {2}".format(case, final_ans[1][0], final_ans[1][1]))



