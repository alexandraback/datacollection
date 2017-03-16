import sys

T = int(sys.stdin.readline().rstrip())

def addOne(xs, x):
    xs[x] += 1

for i in range(T):
    N = int(sys.stdin.readline().rstrip())
    M = {}
    count = [0]*(N)
    for j in range(N):
        for k in map(lambda x: int(x), sys.stdin.readline().rstrip().split(' ')[1:]):
            if not M.has_key(k): M[k] = [j+1]
            else: M[k].append(j+1)
    zas = 0
    for a,b in M.iteritems():
#        print a,b,"fifi"
        if len(b) > 1:
            zas = 1
            count = [0]*(N+1)
            while 1:
                c = []
                map(lambda x: addOne(count, x) ,b)
                for x in b:
                    c.extend(M.get(x, []))
                if not c: break
                b = c[:]
#                print count
#            map(lambda x: addOne(count, x) ,b)
#            print count
            if filter(lambda x: x > 1, count):
                print "Case #" + str(i+1) + ": Yes"
                break
            else: zas = 0
    if not zas: print "Case #" + str(i+1) + ": No"
#    print i+1, M
