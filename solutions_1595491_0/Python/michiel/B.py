wo = [0,1,1,1,2,2,2,3,3,3,4,4,4,5,5,5,
      6,6,6,7,7,7,8,8,8,9,9,9,10,10,10,10]
w = [0,1,2,2,2,3,3,3,4,4,4,5,5,5,6,6,6,7,7,7,
        8,8,8,9,9,9,10,10,10,10,10]
C = int(raw_input())
for c in xrange(C):
    numbers = raw_input().split(" ")
    N,S,p = map(int,numbers[:3])
    scores = map(int,numbers[3:])
    answer = 0
    for score in scores:
        if wo[score]  >= p:
            answer += 1
        elif S > 0 and w[score] >= p:
            answer += 1
            S -= 1
    print "Case #%d: %d" % (c+1,answer)

