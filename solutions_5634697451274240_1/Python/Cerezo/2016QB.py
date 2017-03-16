def flip(s):
    s1 = s.replace('+', 'a')
    s1 = s1.replace('-', '+')
    s1 = s1.replace('a', '-')
    return s1

def Next(sides):
    #bsides = sides.replace('+', '1')
    #bsides = bsides.replace('-', '0')
    #s = bin(int(bsides, 2))
    count = 0
    i = 0
    j = len(sides)
    while j > 0:
        while j> 0 and sides[j-1] == '+':
            j -= 1
        if j <= 0:
            return count
        if sides[0] == '+':
            while sides[i] == '+':
                i += 1
            sinit = flip(sides[:i])
            sides = sinit + sides[i:]
            count += 1
            #print 'leading minus', sides
        sinit = flip(sides[:j])
        sides = sinit[::-1]+sides[j:]
        count += 1
        #print 'switch complete', sides
        #print 'i, j, count', i, j, count
        i = 0
    #print 'all done', sides
    return count

input = open(r'./B-large.in')

T = int(input.readline())

sol = []

for i in xrange(T):
    sides = input.readline().strip()
    #print sides
    sol += [Next(sides)]
    if not i%10: print i

tofile = True
if tofile:
    with open(r'./outputB.txt', 'w') as output:
        for i in range(len(sol)):
            output.write('Case #%s: %s\n' % (i+1, sol[i]))
else:
    print sol
