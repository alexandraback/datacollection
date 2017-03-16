EPS = 1e-6
'''
def best(a, b, ps):
    best = b + 2
    #print "retype:", best
    for t in xrange(a+1):
        right = t*2 + b - a + 1
        wrong = right + b + 1
        # everything before is ok
        probright = 1
        for i in xrange(a-t):
            probright *= ps[i]
            #print probright,
        
        total = right*probright + wrong*(1-probright)
        #print "total:", total, "\tprob:", probright, "\tright:", right, "\twrong:", wrong
        if (best > total):
            best = total

    return best
'''

def best(a, b, ps):
    best = b + 2
    #print "retype:", best
    probright = 1
    for t in xrange(a, -1, -1):
        right = t*2 + b - a + 1
        wrong = right + b + 1
        # everything before is ok
        if t < a:
            probright *= ps[-t-1]
        #print probright,
        
        total = right*probright + wrong*(1-probright)
        #print "back:", t, "\ttotal:", total, "\tprob:", probright, "\tright:", right, "\twrong:", wrong
        if best > total:
            best = total

    return best
    

def test():
    print best(99999, 100000, [0.1]*99999)
    print best(2, 5, [0.6, 0.6])
    print best(1, 20, [1])
    print best(3, 4, [1, 0.9, 0.1])

def main():
    t = int(raw_input())
    i = 1
    while i <= t:
        ab = [int(x) for x in raw_input().split(' ')]
        ps = [float(x) for x in raw_input().split(' ')]
        print "Case #%i: %.6f" % (i, best(ab[0], ab[1], ps))
        i += 1


main()
#test()
