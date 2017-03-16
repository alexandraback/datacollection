for t in range(int(raw_input())):
    scores = map(int, raw_input().split(' '))[1:]
    sorted_scores = sorted(scores)
    X = sum(scores)
    credit = X

    points = []
    pos = {}

    for i,score in enumerate(sorted_scores):
        points.append(0)
        if i+1 < len(scores):
            delta = min(credit, len(points) * (sorted_scores[i+1] - score))
        else:
            delta = credit
        points = map(lambda s: s + float(delta)/len(points)/X, points)
        credit -= delta

        pos[score] = i

    # the last need to be able to beat the one just in front of him
    # with him gaining all the remaining votes
    print "Case #%d:" % (t+1),
    for score in scores:
        print "%.6f" % (100*points[pos[score]]),
    print
