
t = int(raw_input())
for i in range(1, t + 1):
    n = int(raw_input())
    count = [0 for j in range(0, 2501)]
    for j in range(0, 2 * n - 1):
        s = raw_input().split(' ')
        for k in range(0, n):
            q = int(s[k])
            count[q] += 1
    ret = 'Case #{}:'.format(i)
    for j in range(len(count)):
        if count[j] % 2 == 1:
            ret += ' ' + str(j)
    print ret
