def opposite(pancakes):
    return pancakes.replace('-', '*').replace('+', '-').replace('*', '+')


def process(pancakes):
    if '-' not in pancakes:
        return 0
    if len(set(pancakes)) == 1:
        return 1

    for i in xrange(1, len(pancakes)):
        if pancakes[i] != pancakes[i-1]:
            return process(opposite(pancakes[i-1::-1]) + pancakes[i:]) + 1



T = int(raw_input())
for i in xrange(1, T+1):
    print 'Case #%d: %d' % (i, process(raw_input()))
