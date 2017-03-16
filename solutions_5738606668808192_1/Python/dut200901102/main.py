def full(s, full_len):
    return "0" * (full_len - len(s)) + s
    

print "Case #1:"
N, J = 32, 500
for i in xrange(0, J):
    part = "1%s1" % (full(bin(i)[2:], N / 2 - 2))
    print part * 2, 
    print ' '.join(map(str, [int(part, base) for base in xrange(2, 11)]))
    