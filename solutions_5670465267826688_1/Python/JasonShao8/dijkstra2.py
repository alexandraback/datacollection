t = input()
hacks = {}
hacks['11'] = '1'
hacks['1i'] = 'i'
hacks['1j'] = 'j'
hacks['1k'] = 'k'
hacks['i1'] = 'i'
hacks['ii'] = '-1'
hacks['ij'] = 'k'
hacks['ik'] = '-j'
hacks['j1'] = 'j'
hacks['ji'] = '-k'
hacks['jj'] = '-1'
hacks['jk'] = 'i'
hacks['k1'] = 'k'
hacks['ki'] = 'j'
hacks['kj'] = '-i'
hacks['kk'] = '-1'

def mult(a, b):
    neg = 0
    if len(a) > 1:
        neg ^= 1
        a = a[-1]
    if len(b) > 1:
        neg ^= 1
        b = b[-1]
    c = hacks[a + b]
    if neg:
        c = '-' + c
        if len(c) > 2:
            c = c[-1]
    return c

# bc = a return c
def inverse(a, b):
    neg = 0
    if len(a) > 1:
        neg ^= 1
        a = a[-1]
    if len(b) > 1:
        neg ^= 1
        b = b[-1]
    for i in {'1', 'i', 'j', 'k'}:
        c = hacks[b + i]
        if c[-1] == a:
            if len(c) > 1:
                neg ^= 1
                c = c[-1]
            if neg:
                return '-' + i
            else:
                return i

def exp2(a, b):
    if b == 0:
        return '1'
    if a == '1':
        return '1'
    elif a == '-1':
        return str((-1)**b)
    if len(a) > 1:
        c = exp(a[-1], b)
        if b % 2 == 0:
            return c
        else:
            c = '-' + c
            if len(c) > 2:
                c = c[-1]
            return c
    else:
        return exp(a, b)

def exp(a, b):
    if b % 2 == 0:
        return str((-1)**(b/2))
    else:
        if (-1)**(b/2) == 1:
            return a
        else:
            a = '-' + a
            if len(a) > 2:
                a = a[-1]
            return a

for poo in range(t):
    l, x = map(int, raw_input().split())
    s = raw_input()

    if len(s)*x < 3:
        print "Case #" + str(poo + 1) + ": NO"
        continue

    ans = '1'
    # Look for i
    p = min(4, x)
    passed = 0
    temp = s*min(4, x)
    for i in range(len(temp)):
        ans = mult(ans, temp[i])

        if ans == 'i':
            x -= i / l + 1
            passed = (i + 1) % l 
            break
    else:
        print "Case #" + str(poo + 1) + ": NO"
        continue

    # Look for j
    p = min(4, x)
    ans = '1'
    if passed != 0:
        temp = s[passed:] + s*min(4, x)
    else:
        temp = s*min(4, x)
    for i in range(len(temp)):
        ans = mult(ans, temp[i])
        if ans == 'j':
            x -= (i - len(s[passed:])) / l + 1
            passed = temp[i+1:] 
            break
    else:
        print "Case #" + str(poo + 1) + ": NO"
        continue

    passed = passed[:len(passed) % l]
    # Look for k
    ans = '1'
    if len(passed) != 0:
        for i in passed:
            ans = mult(ans, i)
    prod = '1'
    for i in s:
        prod = mult(prod, i)
    ans = mult(ans, exp2(prod, x))
    if ans == 'k':
        print "Case #" + str(poo + 1) + ": YES"
    else:
        print "Case #" + str(poo + 1) + ": NO"


