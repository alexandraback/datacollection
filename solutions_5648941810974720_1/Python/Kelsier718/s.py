t = int(input())
for i in range(1, t + 1):
    s = list(input())
    digits = [0 for j in range(10)]
    c = 0
    for l in s:
        if l == 'Z':
            c = c + 1
    digits[0] = c
    c = 0
    for l in s:
        if l == 'W':
            c = c + 1
    digits[2] = c
    c = 0
    for l in s:
        if l == 'U':
            c = c + 1
    digits[4] = c
    c = 0
    for l in s:
        if l == 'X':
            c = c + 1
    digits[6] = c
    c = 0
    for l in s:
        if l == 'G':
            c = c + 1
    digits[8] = c
    c = 0
    for l in s:
        if l == 'F':
            c = c + 1
    digits[5] = c-digits[4]
    c = 0
    for l in s:
        if l == 'V':
            c = c + 1
    digits[7] = c-digits[5]
    c = 0
    for l in s:
        if l == 'R':
            c = c + 1
    digits[3] = c-digits[0]-digits[4]
    c = 0
    for l in s:
        if l == 'O':
            c = c + 1
    digits[1] = c-digits[0]-digits[2]-digits[4]
    c = 0
    for l in s:
        if l == 'I':
            c = c + 1
    digits[9] = c-digits[5]-digits[6]-digits[8]
    res = ''
    for j in range(10):
        if digits[j] != 0:
            res = res + ''.join(str(j) for tmp in range(digits[j]))
    print("Case #{}: {}".format(i, res))
