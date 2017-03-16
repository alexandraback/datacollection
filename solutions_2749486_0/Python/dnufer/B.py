import sys

f = open(len(sys.argv) > 1 and sys.argv[1] or 'test.in', 'r')

T = int(f.readline())
for t in range(T):
    X, Y = [int(x) for x in f.readline().strip().split()]
    
    path = ''
    
    x = 0
    while x != X:
        if x > 0:
            x -= len(path) + 1
            path += 'W'
        else:
            x += len(path) + 1
            path += 'E'
    
    y_test = Y > 0 and (lambda y: y >= 0) or (lambda y: y > 0)
    
    y = 0
    while y != Y:
        if y_test(y):
            y -= len(path) + 1
            path += 'S'
        else:
            y += len(path) + 1
            path += 'N'
    
    print('Case #%d: %s' % (t + 1, path))

f.close()