with open('C-large-1.in') as infile:
    input = [l.strip() for l in infile.readlines()]

T = int(input.pop(0))

max = long(10 ** 7)
numbers = []

for n in xrange(max + 1):
    strn = str(n)
    if strn == ''.join(reversed(strn)):
        n_2 = str(n ** 2)
        if n_2 == ''.join(reversed(n_2)):
            numbers.append(n)


with open('output.txt', 'w') as f:
    for t in xrange(T):
        A, B = map(long, input.pop(0).split(' ', 2))
        count = len(filter(lambda x: A <= x ** 2 and x ** 2 <= B, numbers))
        f.write('Case #%d: %d\n' % (t + 1, count))
