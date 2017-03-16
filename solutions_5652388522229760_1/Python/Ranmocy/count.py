def solve(num):
    seen = [False for i in range(10)]
    seen_count = 0
    current = num
    for i in xrange(1,1000): # if not found, may be never found
        for c in str(current):
            digit = int(c)
            if not seen[digit]:
                seen[digit] = True
                seen_count += 1
            if seen_count == 10:
                return current
        current += num

    return 'INSOMNIA'

with open('count.in', 'r') as fin:
    with open('count.out', 'w') as fout:
        T = int(fin.readline())
        for i in xrange(1, T+1):
            N = int(fin.readline())
            fout.write('Case #{0}: {1}\n'.format(i, solve(N)))
