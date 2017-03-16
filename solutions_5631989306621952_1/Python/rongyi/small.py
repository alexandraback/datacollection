def theLastWord(S):
    res = ''
    for i in S:
        if res == '':
            res += i
        elif ord(i) < ord(res[0]):
            res += i
        else:
            res = i + res
    return res


n = int(input())
for i in range(1, n + 1):
    t = input()
    print("Case #" + str(i) + ": " + theLastWord(t))