#  --*-coding:utf-8-*--

def f(k, c, s):
    if (k//c > s):
        return 'IMPOSSIBLE'

    ps = []
    for i in range(0, k, c):
        p = 0
        for j in range(i, min([i+c, k])):
            p = p*k + j

        ps.append(p+1)


    return ' '.join(map(str,ps))

t = int(input())
for i in range(t):
    (k,c,s) = map(int, input().split())
    print('Case #' + str(i+1) + ':', f(k, c, s));


