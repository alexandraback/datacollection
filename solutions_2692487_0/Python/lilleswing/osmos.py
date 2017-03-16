__author__ = 'karl_leswing'


def osmos_helper(a, values):
    #print values
    if values == list():
        return 0
    if a == 1:
        return len(values)
    moves = 0
    while a <= values[0]:
        a += (a-1)
        moves += 1
    by_add = moves + osmos_helper(a + values[0], values[1:])
    #print "by_add = %d" % by_add
    return min((len(values), by_add))


def osmos(a, n, values):
    values = sorted(values)
    #print values
    index = 0
    while index < len(values) and values[index] < a:
        a += values[index]
        index += 1
        #print a
    moves = osmos_helper(a, values[index:])
    return moves

if __name__ == '__main__':
    fpath = "A-small-attempt0"
    fout = open("%s.out" % fpath, "w")
    data = open("%s.in" % fpath).readlines()
    rounds, data = int(data[0]), data[1:]
    for i in xrange(1, rounds + 1):
        a, n = map(lambda x: int(x), data[0].split(' '))
        values = map(lambda x: int(x), data[1].split(' '))
        data = data[2:]
        moves = osmos(a, n, values)
        print "Case #%d: %d" % (i, moves)
        fout.write("Case #%d: %d\n" % (i, moves))
    fout.close()
