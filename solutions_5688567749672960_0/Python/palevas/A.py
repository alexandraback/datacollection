T = int(raw_input())



def good_for_flip(l):
    l = str(l)
    res = False
    if l[-1] == '1':
        for i in range(len(l)/2):
            if int(l[i]) > int(l[-1-i]):
                res = True
                return int(l[::-1])
            if int(l[i]) < int(l[-1-i]):
                break
    return False

for tc in range(1, T+1):
    n = int(raw_input())
    t = 0
    while n > 0:
        nn = good_for_flip(n)
        if nn:
            n = nn
#            print 'Flip:', n
        else:
            n -= 1
#            print 'Decr:', n
        
        t += 1
    print "Case #%d: %d" % (tc, t)
