import sys

sys.stdin = open("A-large.in", "r")
sys.stdout=open("out.txt", "w")

T=input()
for _ in xrange(T):
    n = input()
    s = set()
    for i in range(1,200):
        s |= (set(str(n*i)))
        if len(s) == 10:
            break
    print "Case #%d:"  %(_+1),
    if len(s) == 10:
        print i*n
    else:
        print "INSOMNIA"
