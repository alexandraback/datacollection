
def check(cache, id):
    info    = [id]
    if len(cache[id]) == 0:
        return info

    for i in cache[id]:
        info    += check(cache, int(i))

    return info

def solve(num, data):
    cache   = {}
    for i in xrange(len(data)):
        tmp = data[i].split(' ')
        if tmp[0] == 0:
            cache[i+1]    = []
        else:
            cache[i+1]    = tmp[1:]

    for i in xrange(num):
        info    = []
        info    = check(cache, i+1)
        l   = len(info)
        info = list(set(info))
        if l <> len(info):
            return True

    return False




if __name__ == '__main__':

    import sys
    T   = int(sys.stdin.readline())
    for i in xrange(T):
        num = int(sys.stdin.readline())
        data    = []
        for j in xrange(num):
            data.append(sys.stdin.readline().strip())
        out = solve(num, data)

        if out:
            out = "Yes"
        else:
            out = "No"
        print "Case #%s: %s" % (i+1, out)

