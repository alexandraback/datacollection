m = input()
for test in range(m):
    z = '+'
    n = raw_input()
    ans = 0
    for i in range(len(n)):
        cur = n[-1 - i]
        if (cur == z):
            continue
        ans += 1
        if z == '+':
            z = '-'
        else:
            z = '+'
    print 'Case #' + str(test + 1) + ': ' + str(ans)

