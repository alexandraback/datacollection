
def solve(case, inf, onf):
    srow, scolumn = inf.readline().split(' ')
    r = int(srow)
    c = int(scolumn)
    
    possible = True
    
    lawn = [ [0     for x in xrange(c)] for y in xrange(r) ]  # @UnusedVariable
    test = [ [False for x in xrange(c)] for y in xrange(r) ]
    
    print 'Case #' + str(case) + ':', r, c
    for y in xrange(r):
        params = inf.readline().split(' ')
        for x in xrange(c):
            height = int(params[x])
            lawn[y][x] = height
        
    if r > 1 and c > 1:
        # for y in xrange(r): print lawn[y]
        
        for y in xrange(r):
            row = lawn[y]
            m = max(row)
            for idx, val in enumerate(row):
                if idx == 0: continue
                if val >= m: test[y][idx] = True
            for idx, val in enumerate(reversed(row)):
                if idx == 0: continue
                if val >= m: test[y][len(row) - idx - 1] = True
        
        # for y in xrange(r): print test[y]
        
        for x in xrange(c):
            m = 0
            for y in xrange(r): m = max(m, lawn[y][x])
            
            for y in xrange(r):
                if y == 0: continue
                val = lawn[y][x]
                if val >= m: test[y][x] = True
            for y in xrange(r, 0, -1):
                if y == r: continue
                val = lawn[y-1][x]
                if val >= m: test[y-1][x] = True
        
        for y in xrange(r):
            if False in test[y]: possible = False
            # print test[y]
        
    print 'Possible:', 'YES' if possible else 'NO'
    onf.write('Case #' + str(case) + ': ' + ('YES' if possible else 'NO'))
    onf.write('\r\n')
    
if __name__ == '__main__':
    with open('../b.in', 'r') as input_file:
        with open('../b.out', 'w') as output_file:
            cases = int(input_file.readline())
            for case in xrange(cases):
                solve(case + 1, input_file, output_file)
