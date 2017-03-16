IN = open('input.txt', 'r')
OUT = open('output.txt', 'w')

NUM_TESTS = int(IN.readline())

for test in xrange(NUM_TESTS):
    N = int(IN.readline())
    pages = []
    for i in xrange(2*N-1):
        pages.append(map(int,IN.readline().split()))
    
    heightCount = [0] * 2501
    for i in xrange(2*N-1):
        for j in xrange(N):
            heightCount[pages[i][j]] += 1
    
    missing = []
    for h in xrange(1, 2501):
        if heightCount[h] % 2 == 1:
            missing.append(h)
    
    answer = ' '.join(map(str,missing))
        
    OUT.write('Case #{}: {}\n'.format(test+1, answer))
    print test+1, answer

IN.close()
OUT.close()
