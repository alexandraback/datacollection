T = int(raw_input().strip())

for i in xrange(T):
    C, D, V = map(int, raw_input().strip().split(' '))
    numbers = sorted(map(int, raw_input().strip().split(' ')))
    ln = len(numbers)
    inserts = 0

    if numbers[0] != 1:
        numbers.insert(0, 1)
        inserts += 1

    covered = C
    curr = 1

    while curr < len(numbers) and covered < V:
        if covered < numbers[curr] - 1:
            next = covered + 1
            numbers.insert(curr, next)
            inserts += 1

        covered += C * numbers[curr]
        curr += 1

    while covered < V:
        next = covered + 1
        numbers.append(next)
        covered += C * next
        inserts += 1

    print "Case #%s: %s" % (i + 1, inserts)
