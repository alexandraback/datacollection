def parse(filename):
    input = open('%s.in' % filename, 'r')
    cases = int(input.readline())
    results = []
    for i in range(cases):
        name, n = input.readline()[:-1].split(' ')
        result = process(name, n)
        results.append('Case #%s: %s\n' % (i + 1, result))
    input.close()
    output = open('%s.out' % filename, 'w')
    output.writelines(results)
    output.close()

vowels = ['a', 'e', 'i', 'o', 'u']

def process(name, n):
    n = int(n)
    l = len(name)
    nvalue = 0
    consecutive = 0
    starts = 0
    for a in range(0, l):
        if name[a] in vowels:
            consecutive = 0
        else:
            consecutive += 1
            if consecutive >= n:
                before = (a - (n - 1)) - starts
                after = ((l - 1) - a)
                nvalue += (before + 1) * (after + 1)
                starts += 1
    return nvalue

parse('A-small-attempt2')

