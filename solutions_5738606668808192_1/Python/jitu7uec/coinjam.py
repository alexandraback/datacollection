T = input()

for x in range(T):
    N, J = raw_input().split()
    N, J = int(N), int(J)
    #print "N=%d J=%d" % (N, J)
    magic_func_1 = lambda x: str(bin(x)).replace("0b","").zfill(N/2-2)
    magic_func_2 = lambda y: " ".join(str(int(y, x)) for x in range(2, 11))
    print "Case #%s:" % (x+1)
    for j in range(J):
        half = "1%s1" % magic_func_1(j)
        print "%s%s %s" % (half, half, magic_func_2(half))
