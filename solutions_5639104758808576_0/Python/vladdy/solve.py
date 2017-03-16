def solve(s_max, ss):

    standing = 0
    invited = 0
    for pos, count in enumerate(ss):
        cur_s = pos + 1
        standing += count
        while (standing+invited) < cur_s:
            invited += 1
            
    return invited



T = int(raw_input())
for t in xrange(T):
    [s_max, s] = raw_input().split()
    s_max = int(s_max)
    ss = map(int, list(s))

    print "Case #%i: %i" % (t+1, solve(s_max, ss)) 
