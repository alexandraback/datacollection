def sig(S):
    count = {}
    for c in S:
        if not c in count:
            count[c] = 0
        count[c] += 1
    return count

zero = 'ZERO'
one = 'ONE'
two = 'TWO'
three = 'THREE'
four = 'FOUR'
five = 'FIVE'
six = 'SIX'
seven = 'SEVEN'
eight = 'EIGHT'
nine = 'NINE'

zeroS = sig(zero)
oneS = sig(one)
twoS = sig(two)
threeS = sig(three)
fourS = sig(four)
fiveS = sig(five)
sixS = sig(six)
sevenS = sig(seven)
eightS = sig(eight)
nineS = sig(nine)
digits = [zeroS, twoS, fourS, fiveS, sixS, sevenS, eightS, nineS, oneS, threeS]
order = [0, 2, 4, 5, 6, 7, 8, 9, 1, 3]

def canTake(sign, d):
    for c in d.keys():
        if not c in sign or sign[c] < d[c]:
            return False
    else:
        return True

def solve(S):
    s = []
    sign = sig(S)
    assert(len(digits) == 10)
    for i in range(len(digits)):
        included = True
        d = digits[i]
        while canTake(sign, d):
            s.append(order[i])
            for c in d.keys():
                sign[c] -= d[c]
    for c in sign.keys():
        assert(sign[c] == 0)
    s.sort()
    return ''.join(map(str, s))

T = int(input())
for c in range(1, T+1):
    S = input()
    print('Case #' + str(c) + ': ' + solve(S))
