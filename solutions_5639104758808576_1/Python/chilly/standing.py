with open('input', 'r') as f:
    num = int(f.readline().strip())
    data = f.readlines()
    for idx, row in enumerate(data):
        total, val = row.strip().split(' ')
        total = int(total)
        add = 0
        current = 0
        current += int(val[0])
        for i in xrange(1, total+1):
            if current < i:
                add += i-current
                current = i
            current += int(val[i])
        print 'Case #' + str(idx+1) + ': ' + str(add)
