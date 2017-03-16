
num_lines = int(raw_input(''))
lines = list()
for i in range(num_lines):
    lines.append(raw_input(''))

# Integer partitions precomputed with Maxima (it's like the FOSS equivalent of
# Mathematica, a la Octave, except it isn't particularly amazing, and I'm
# broke)
#
# P(n, 3) with no two numbers differing by more than two is == 2 for n > 1
# Here, {0, 1, 29, 30} have only one legal representation, and 2-28 have
# exactly two: one normal and one "surprising"
normal = [0, 1, 1, 1, 2, 2, 2, 3, 3, 3, 4, 4, 4, 5, 5, 5, 6, 6, 6, 7, 7, 7, 8,
        8, 8, 9, 9, 9, 10, 10, 10]
surprising = [-1, -1, 2, 2, 2, 3, 3, 3, 4, 4, 4, 5, 5, 5, 6, 6, 6, 7, 7, 7, 8,
        8, 8, 9, 9, 9, 10, 10, 10, -1, -1]

# I'd have to make my decision logic a bit more general
# to allow this to change

for case, line in enumerate(lines):
    n, s_, p, scores = line.split(' ', 3)
    n, s_, p = map(int, (n, s_, p))
    s = s_
    # sort scores descending so we can get largest values first
    scores_ = reversed(sorted(map(int, scores.split())))
    satisfying = 0
    for score in scores_:
        if score < 2:
            if p <= score:
                satisfying += 1
            continue
        elif score > 28:
            # can't be surprising
            satisfying += 1
            continue
        # score is now in [2,28]
        if normal[score] >= p:
            satisfying += 1
        elif surprising[score] >= p and s > 0:
            s -= 1
            satisfying += 1
    #print "Case #{0}: {2}, {3}, {4}, {5} => {1}".format(case+1, satisfying,
            #n, s_, p, scores)
    print "Case #{0}: {1}".format(case+1, satisfying)

