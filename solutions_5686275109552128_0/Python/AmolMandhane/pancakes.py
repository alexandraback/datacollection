import math


def min_time(plates):
    maxm = max(plates)
    if maxm == 1:
        return 1
    max_splits = int(math.ceil(math.sqrt(maxm)))
    split_time = float('Inf')
    plates[plates.index(maxm)] = 0
    for num_splits in xrange(2, max_splits+1):
        elem = int(maxm/num_splits)
        splits = [elem] * num_splits
        rem = maxm % num_splits
        for i in xrange(rem):
            splits[i] += 1
        new_plates = plates + splits
        time = min_time(new_plates) + num_splits - 1
        if time < split_time:
            split_time = time
    return min(maxm, split_time)

for T in xrange(input()):
    D = input()
    Pi = map(int, raw_input().split(" "))
    print "Case #%d: %d" % (T+1, min_time(Pi))
