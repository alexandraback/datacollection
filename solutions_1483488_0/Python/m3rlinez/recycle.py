# Arghhhhhhh! Can't think of any efficient algo :((

def count_pair(n, a, b, visited):

    visited[n] = True
    
    l = len(str(n))
    nn = n * 10**l + n # so 123 becomes 123123

    series = set([n])
    for i in xrange(1,l):
        tmp = nn / 10**i # removes last i digits
        tmp %= 10**l # get only the last l digits
        
        if a <= tmp <= b:
            series.add(tmp)
            visited[tmp] = True
    
    # print series
    c = len(series)
    return c * (c-1) / 2

def solve(a,b):
    visited = [False] * (b + 1)
    count = 0
    for i in xrange(a, b + 1):
        if not visited[i]:
            count += count_pair(i, a, b, visited)
        
    return count

def profile_run():
    for i in range(50):
        solve(1000000,2000000)
        print 'Done #', i

if __name__ == '__main__':
    
    if False: # Do profile run?
        import cProfile
        cProfile.run('profile_run()')
        exit(0)
        
    fi = open('C-small-attempt0.in', 'r')
    fo = open('recycle.out', 'w')
    
    n = int(fi.readline())
    for i in range(1, n + 1):
        a,b = [int(x) for x in fi.readline().split()]
        output = 'Case #%d: %d' % (i, solve(a,b))
        fo.write("%s\n" % output)
        print output
    
    fi.close()
    fo.close()
    
        
    