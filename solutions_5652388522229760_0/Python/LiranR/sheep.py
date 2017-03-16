T = int(raw_input())

for i in xrange(1,T+1):
    N = int(raw_input())

    print "Case #%d:"%i,
    if N == 0:
        print "INSOMNIA"
        continue

    digits = set()
    cur = 0
    while len(digits) < 10:
        cur += N
        digits = digits | set(str(cur))
    print cur
    
