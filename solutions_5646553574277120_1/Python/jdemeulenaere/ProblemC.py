import itertools

data = open("input/problemc.txt")
nb_cases = int(data.readline())

def binary_search_bounds(array, value, low, high):
    if low == high:
        return -1

    mid = (low + high) / 2
    mid_value = array[mid]
    if mid_value < value:
        return binary_search_bounds(array, value, mid + 1, high)
    elif mid_value > value:
        return binary_search_bounds(array, value, low, mid)
    else:
        return mid

for z in xrange(nb_cases):
    print "Case #%d:" % (z + 1),
    # print

    C,D,V = [int(x) for x in data.readline().split(" ")]
    den = [int(x) for x in data.readline().split(" ")]

    possibles = []
    for size in xrange(1,len(den)+1):
        combinations = itertools.combinations(den, size)
        for comb in combinations:
            # print [x for x in comb],"=>"
            # print sum(comb)
            possibles.append(sum(comb))

    possibles.sort()
    count = 0
    for i in xrange(1,V+1):
        if i not in possibles:
            possibles.append(i)
            for j in xrange(len(possibles)-1):
                possibles.append(possibles[j]+i)
            count += 1
    print count
