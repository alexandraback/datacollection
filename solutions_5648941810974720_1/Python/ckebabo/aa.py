numbers = ["ZERO", "ONE", "TWO", "THREE", "FOUR", "FIVE", "SIX", "SEVEN", "EIGHT", "NINE"]

def foo(digit, chars, num):
    for ch in numbers[num]:
        chars[ord(ch)] -= digit[num]

    return chars

for cs in xrange(int(raw_input())):
    S = raw_input()

    chars = [0]*300
    for ch in S:
        chars[ord(ch)] += 1

    digits = [0]*10

    m = [(0,'Z'),
            (4, 'U'),
            (8, 'G'),
            (2, 'W'),
            (6, 'X'),
            (7, 'S'),
            (5, 'V'),
            (1, 'O'),
            (3, 'H'),
            (9, 'N')]

    for k,v in m:
        if k==9:
            digits[k] = chars[ord(v)]/2
        else:
            digits[k] = chars[ord(v)]
        chars = foo(digits, chars, k)

    s = ''
    for i in xrange(10):
        if digits[i]>0:
            s += str(i)*digits[i]

    print 'Case #%d:'%(cs+1), s
