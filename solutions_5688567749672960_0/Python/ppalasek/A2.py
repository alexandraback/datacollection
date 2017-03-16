def reverse(n):
    n = reversed(str(n))
    return int(''.join(n))

t = int(raw_input())

n = 1000000

value = []

for i in xrange(n + 1):
    value.append(i)

for i in xrange(n + 1):
    rev = reverse(i)

    if (rev > i and value[rev] > value[i] + 1):
        value[rev] = value[i] + 1

for i in xrange(1, n + 1):
    value[i] = min(value[i], value[i - 1] + 1)

for x in xrange(t):
    n = int(raw_input())

    print 'Case #%s:' % (x+1), value[n]
