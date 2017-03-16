def f(s):
    maxChar = None
    ans = []

    for c in s:
        if (maxChar == None or c >= maxChar):
            ans.insert(0, c)
            maxChar = c
        else:
            ans.append(c)

    return ''.join(ans)

t = int(input())
for i in range(t):
    print('Case #' + str(i+1) + ':', f(input()))


