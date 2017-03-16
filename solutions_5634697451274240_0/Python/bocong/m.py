def reverse(p, n): # reverse first n pancakes
    return [not i for i in reversed(p[:n])] + p[n:]

def index_last_neg(p): #find last negative in list
    return (len(p) - 1) - p[::-1].index(False)

def index_last_pos(p):
    return (len(p) - 1) - p[::-1].index(True)

def index_trailing_pos(p):
    return index_last_neg(p) + 1

def f(inp):
    p = inp
    moves = 0
    while len(p) != sum(p):
        if (not p[0]):
            p = reverse(p, index_last_neg(p) + 1)
        elif (p[0]):
            p = reverse(p, index_last_pos(p[:index_trailing_pos(p)]) + 1)
        moves += 1
    return moves


T = int(raw_input())
for t in xrange(1, T + 1):
    inp = [(True if s == '+' else False) for s in raw_input()]
    print "Case #{}: {}".format(t, f(inp))