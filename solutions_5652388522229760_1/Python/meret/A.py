d = int(raw_input())

for i in range(1, d+1):
    n = int(raw_input())
    print 'Case #' + str(i) + ':',
    if n == 0:
        print 'INSOMNIA'
        continue
    seen = set()
    last = 0
    while len(seen) < 10:
        last += n
        for j in str(last):
            seen.add(j)
    print last
