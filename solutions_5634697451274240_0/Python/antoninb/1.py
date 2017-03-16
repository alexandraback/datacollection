def invert(s, x):
    for i in xrange(x / 2):
        a = s[i]
        b = s[x - 1 - i]
        s[i] = '+' if (b == '-') else '-'
        s[x - 1 - i] = '+' if (a == '-') else '-'
    if x % 2 == 1:
        s[x / 2] = '+' if (s[x / 2] == '-') else '-'
    return s

def find_res(s, x):
    if x == 0:
        return 0
    if s[x - 1] == '+':
        return find_res(s, x - 1)
    elif s[0] == '-':
        i = 0
        while i < x and s[i] == '-':
            i += 1
        return 1 + find_res(invert(s, x), x - i)
    else:
        i = 0
        while i < x and s[i] == '+':
            i += 1
        return 1 + find_res(invert(s, i), x)
        

with open("in") as f:
    T = int(f.readline())
    for t in xrange(T):
        stack = list(f.readline())
        stack = stack[:-1]
        r = find_res(stack, len(stack))
        print "Case #{}: {}".format(t + 1, r)
