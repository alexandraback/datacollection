MAX_VAL = 100000000000000

def ispalin(x):
    return str(x) == str(x)[::-1]

def generatelist():
    res = {}
    for i in xrange(1, 10000):
        n = int(str(i) + str(i)[::-1])
        if n * n <= MAX_VAL and ispalin(n * n): res[n * n] = True
        n = int(str(i) + str(i)[::-1][1:])
        if n * n <= MAX_VAL and ispalin(n * n): res[n * n] = True
    return sorted(res.keys())

if __name__ == '__main__':
    L = generatelist()
    for test in xrange(int(raw_input().strip())):
        a, b = map(int, raw_input().strip().split())
        print 'Case #' + str(test + 1) + ': ' + str(len([l for l in L if l >= a and l <= b]))
