



T = raw_input()
T = int(T)

for i in range(T):
    S = raw_input()
    S = list(S)

    num = []

    while 'Z' in S:
        num.append(0)
        for c in 'ZERO':
            S.remove(c)

    while 'W' in S:
        num.append(2)
        for c in 'TWO':
            S.remove(c)

    while 'U' in S:
        num.append(4)
        for c in 'FOUR':
            S.remove(c)

    while 'X' in S:
        num.append(6)
        for c in 'SIX':
            S.remove(c)

    while 'G' in S:
        num.append(8)
        for c in 'EIGHT':
            S.remove(c)

    while 'S' in S:
        num.append(7)
        for c in 'SEVEN':
            S.remove(c)

    while 'F' in S:
        num.append(5)
        for c in 'FIVE':
            S.remove(c)

    while 'R' in S:
        num.append(3)
        for c in 'THREE':
            S.remove(c)

    while 'I' in S:
        num.append(9)
        for c in 'NINE':
            S.remove(c)

    while 'O' in S:
        num.append(1)
        for c in 'ONE':
            S.remove(c)

    num.sort()
    num = [str(x) for x in num]
    print("Case #%d: %s" % (i + 1, ''.join(num)))

    


