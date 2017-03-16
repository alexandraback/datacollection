T = int(raw_input())

DEBUG = True

for i in range(1, T+1):
    sequence_length, complexity, num_students = map(int, raw_input().split(' '))
    print 'Case #%d:' % i,
    if complexity * num_students < sequence_length:
        print 'IMPOSSIBLE'
        continue
    to_check = 0
    chosen = set()
    for _ in range(num_students):
        index = 0
        for _ in range(complexity):
            index = index * sequence_length + to_check
            to_check = (to_check + 1) % sequence_length
        assert index < sequence_length ** complexity
        if index in chosen:
            break
        chosen.add(index)
        print (index + 1),
    print
