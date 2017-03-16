from sys import stdout
T=int(raw_input())

for ts in xrange(1,T+1):
    print "Case #%s:" % ts
    N, J = [int(x) for x in raw_input().split(' ')]
    #print N, J
    pow2 = 2 ** (N/2 - 1) 
    for x in range(pow2 + 1, pow2+1+2*J,2):
        b = bin(x)[2:]
        bb = ""
        for c in b: bb += c*2
        stdout.write(bb)
        for b in range(2,11):
            stdout.write(' ' + str(1+b))
        stdout.write('\n')
