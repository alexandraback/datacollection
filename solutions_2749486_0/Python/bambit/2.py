from operator import itemgetter

with open('B-small-attempt-0.in') as f:
    num_cases = int(f.readline().replace('\n', ''))    
    for case in xrange(1, num_cases+1):
        x, y = [ int(x) for x in f.readline().replace('\n', '').split() ]
        
        path = ''
        if y > 0:
            path += 'SN'*y
        elif y < 0:
            path += 'NS'*(-y)
        if x > 0:
            path += 'WE'*x
        elif x < 0:
            path += 'EW'*(-x)
        print 'Case #%d: %s' % (case, path)         

