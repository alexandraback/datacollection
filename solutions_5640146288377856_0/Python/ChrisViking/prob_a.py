
def search_when_one_found(W, remaining_cols):

    tries = 0
    undecided = remaining_cols - W
    #print 'h', undecided, remaining_cols, tries

    if undecided == 0:
        tries += W
    else:
        # these remaining squares are hit using dichotomy

        while undecided > 0:
            #print undecided
            tries += 1
            if undecided == 1:
                break
            undecided = (undecided-1) /2

        # hit the remaining squares
        tries += W

    return min(tries, W+1)

def analyze(R,C,W):
    # first R-1 columns:
    # hit once every W squares

    if W == 1:
        return R*C

    tries = (R-1) * ((C-1)/W)

    # last row: hit every W, except for the last time
    # at the end, W + C%W squares remain
    # [x, x, x, X, ..., x, O, O, O, x]

    if W==C:
        remaining_cols = W
        tries += W
    else:
        remaining_cols = W + (C%W)
        if C >= 2*W:
            v1 = (C-remaining_cols)/W + search_when_one_found(W, remaining_cols)
            v2 = (C-remaining_cols)/W -1 + search_when_one_found(W, 2*W-1)
            tries += max(v1, v2)
        else:
            remaining_cols = W+(C%W)

            tries += (C-remaining_cols)/W

            # all that remains are remaining_cols square and W squares are covered,
            # we know the position of remaining_cols - 2 (remaining_cols-W)

            tries += search_when_one_found(W, remaining_cols)

    return tries

import sys

print analyze(1,6,4), 5
print analyze(1,6,2), 4
print analyze(1,4,2), 3
print analyze(1,7,7), 7
print analyze(1, 8, 4), 5
print analyze(1, 8, 5), 6
print analyze(1, 2, 2), 2
print analyze(1,9,7), 8

#sys.exit()

#fname = 'test_a.txt'
fname = 'A-small-attempt5.in'
#fname = 'A-large.in'

f = open(fname, 'r')
data = f.read().split('\n')
f.close()

res_file = open(fname + '.res', 'w')

T = int(data[0])
data = data[1:]

for i in range(T):
    R,C,W = [int(x) for x in data[i].split(' ')][:3]

    res = analyze(R,C,W)
    print R,C,W, res
    print >> res_file, 'Case #%s: %s' % (i+1, res)

res_file.close()