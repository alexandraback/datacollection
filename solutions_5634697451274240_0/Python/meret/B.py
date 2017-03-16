d = int(raw_input())

for i in range(1, d+1):
    print 'Case #' + str(i) + ':',
    s = raw_input() + '+'
    result = 0
    for i in range(len(s) - 1):
        if s[i] != s[i + 1]:
            result += 1
    print result
