N = input()

def solve(line):
    total = 0
    miss = 0
    for shyness, n in enumerate(line):
        if total < shyness: 
            miss += shyness - total
            total = shyness
        total += int(n)
    return miss
            
for i in range(1, N+1):
    print 'Case #%d: %d' % (i, solve(raw_input().split()[1]))

