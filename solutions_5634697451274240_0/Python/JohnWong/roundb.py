fn = "sample.in"
debug = False

def process(num, n):
    t = '+'
    c = 0
    for i in xrange(len(n) - 1, -1, -1):
        if n[i] != t:
            c += 1
            t = '+' if t == '-' else '-'
            pass
        pass
    print('Case #' + str(num) + ': ' + str(c))

# process(0, '--+-')
with open(fn) as f:
    n = int(f.readline()[:-1])
    if debug:
        print('count: ' + n)
    for i in range(1, n + 1):
        line = f.readline()
        if line.rfind('\n') > 0:
            line = line[:-1]
        process(i, line)
        pass
    pass
    print('')

