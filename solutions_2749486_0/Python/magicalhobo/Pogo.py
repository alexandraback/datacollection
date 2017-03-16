def parse(filename):
    input = open('%s.in' % filename, 'r')
    cases = int(input.readline())
    results = []
    for i in range(cases):
        x, y = input.readline()[:-1].split(' ')
        result = process(x, y)
        results.append('Case #%s: %s\n' % (i + 1, result))
    input.close()
    output = open('%s.out' % filename, 'w')
    output.writelines(results)
    output.close()

def process(x, y):
    x = int(x)
    y = int(y)
    result = ''
    if x > 0:
        for i in range(0, x):
            result += 'WE'
    elif x < 0:
        for i in range(0, -x):
            result += 'EW'        
    if y > 0:
        for i in range(0, y):
            result += 'SN'
    elif y < 0:
        for i in range(0, -y):
            result += 'NS'
    return result

parse('B-small-attempt0')
