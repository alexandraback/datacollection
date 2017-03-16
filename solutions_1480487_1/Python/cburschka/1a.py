def score(contestants):
    x = sum(contestants)
    n = len(contestants)
    first = [(200.0/n - 100.0*j/x) for j in contestants]
    eliminable = map(lambda k:k>=0, first)
    if all(eliminable):
        return first
    second = [0]*n
    average = sum([e*s for e,s in zip(eliminable, contestants)])
    for i,c in enumerate(contestants):
        if not eliminable[i]:
            second[i] = 0.0
        else:
            second[i] = 100.0*average/sum(eliminable)/x + 100.0/sum(eliminable) - 100.0*c/x
    return second





n = int(raw_input())

for i in range(n):
    contestants = map(int, raw_input().split()[1:])
    scores = score(contestants)    
    print "Case #%d: %s" % (i+1, " ".join(map(str, scores)))
