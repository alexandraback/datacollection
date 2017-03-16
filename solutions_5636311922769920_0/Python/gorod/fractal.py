


def simple_case(k, c):
    inc = k**(c-1)
    pos = 1
    l = []
    for i in range(k):
        l.append(pos)
        pos += inc
    return " ".join(map(lambda x: str(x), l))

t = int(raw_input())
for i in xrange(1, t + 1):
   
    k, c, s = [int(s) for s in raw_input().split(" ")]
    if s == k:
        print "Case #{}: {}".format(i, simple_case(k, c))
