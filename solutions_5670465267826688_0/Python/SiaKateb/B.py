__author__ = 'siavash'

dij = [[0, 1, 2, 3, 4], [0, 1, 2, 3, 4], [0, 2, -1, 4, -3], [0, 3, -4, -1, 2], [0, 4, 3, -2, -1]]
'''
t = input()
for i in xrange(t):
    l, x = (raw_input()).split(" ")
    l, x = int(l), int(x)

    string = raw_input()
    nums = []
    for c in string:
        if c == 'i':
            nums.append(2)
        elif c == 'j':
            nums.append(3)
        elif c == 'k':
            nums.append(4)

    length = x * l
    if length < 3:
        print "Case #{0}: {1}".format(i + 1, 'NO')
        continue

    nums *= x
    left = 1
    res = nums[0]
    right = length - 1
    sign = 1
    ok = True
    while res != 2 and left < right:
        if res < 0:
            res = -res
            sign = -1
        else:
            sign = 1
        res = dij[res][nums[left]] * sign
        if res == 2:
            ok = True
            break
        ok = False

        left += 1
    if not ok:
        print "Case #{0}: {1}".format(i + 1, 'NO')
        continue
    res = nums[right]
    right -= 1
    sign = 1
    ok = True
    while res != 4 and left < right:
        if res < 0:
            res = -res
            sign = -1
        else:
            sign = 1
        res = dij[nums[right]][res] * sign
        if res == 4:
            ok = True
            break
        ok = False

        right -= 1
    if not ok:
        print "Case #{0}: {1}".format(i + 1, 'NO')
        continue
    left += 1

    while left < right:
        res = dij[res][nums[left]] * sign
        if res == 3 and left == right -1:
            ok = True
            break
        if res < 0:
            res = -res
            sign = -1
        else:
            sign = 1
        left += 1
    if not ok:
        print "Case #{0}: {1}".format(i + 1, 'NO')
    else:
        print "Case #{0}: {1}".format(i + 1, 'YES')

'''


def multiply(a, b):
    s1, c1 = a
    s2, c2 = b
    s, c = s1 * s2, '1'
    if c1 == '1':
        c = c2
    elif c2 == '1':
        c = c1
    elif c1 == c2:
        s *= -1
        c = '1'
    elif c1 == 'i' and c2 == 'j':
        c = 'k'
    elif c1 == 'i' and c2 == 'k':
        s *= -1
        c = 'j'
    elif c1 == 'j' and c2 == 'k':
        c = 'i'
    elif c1 == 'j' and c2 == 'i':
        s *= -1
        c = 'k'
    elif c1 == 'k' and c2 == 'i':
        c = 'j'
    elif c1 == 'k' and c2 == 'j':
        s *= -1
        c = 'i'
    return s, c


def solve():

    for t in range(int(input())):


        L, X = (raw_input()).split(" ")
        L, X = int(L), int(X)
        single = str(raw_input())

        val = (1, '1')
        for c in single * (X % 4):
            val = multiply(val, (1, c))

        result = val == (-1, '1')

        if result:

            S = single * (X % 4 + (4 if X >= 4 else 0))

            p1 = p2 = -1

            n1 = (1, '1')
            for i in range(len(S)):
                n1 = multiply(n1, (1, S[i]))
                if n1 == (1, 'i'):
                    p1 = i
                    break

            n2 = (1, '1')
            for i in range(len(S)-1, -1, -1):
                n2 = multiply((1, S[i]), n2)
                if n2 == (1, 'k'):
                    p2 = i
                    break

            result = (p1 > -1 and p2 > -1) and p1 < p2 + (X * L - len(S))

        print 'Case #{0}: {1}'.format((t+1),'YES' if result else 'NO')

solve()