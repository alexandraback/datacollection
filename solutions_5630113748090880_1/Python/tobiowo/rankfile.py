"""
When Sergeant Argus's army assembles for drilling, they stand in the shape of an N by N square grid, with exactly one soldier in each cell. Each soldier has a certain height.

Argus believes that it is important to keep an eye on all of his soldiers at all times. Since he likes to look at the grid from the upper left, he requires that:

Within every row of the grid, the soldiers' heights must be in strictly increasing order, from left to right.
Within every column of the grid, the soldiers' heights must be in strictly increasing order, from top to bottom.
Although no two soldiers in the same row or column may have the same height, it is possible for multiple soldiers in the grid to have the same height.

Since soldiers sometimes train separately with their row or their column, Argus has asked you to make a report consisting of 2*N lists of the soldiers' heights: one representing each row (in left-to-right order) and column (in top-to-bottom order). As you surveyed the soldiers, you only had small pieces of paper to write on, so you wrote each list on a separate piece of paper. However, on your way back to your office, you were startled by a loud bugle blast and you dropped all of the pieces of paper, and the wind blew one away before you could recover it! The other pieces of paper are now in no particular order, and you can't even remember which lists represent rows and which represent columns, since you didn't write that down.

You know that Argus will make you do hundreds of push-ups if you give him an incomplete report. Can you figure out what the missing list is?
"""
from collections import Counter
import fileinput


def get_missing_row(N, rows):
    """
    rows and heights aren't unique, but each soldier should appear exactly twice
    """
    c = Counter()
    for row in rows:
        c.update(row)
    missing_row = []
    for height, value in c.iteritems():
        if value % 2 != 0:
            missing_row.append(height)
    missing_row = sorted(missing_row)
    return ' '.join([str(x) for x in missing_row])

i = 1
f = enumerate(fileinput.input())
for _, line in f:
    if fileinput.isfirstline():
        num_cases = int(line)
    else:
        N = int(line)
        rows = []
        for _ in range(2 * N - 1):
            __, nextrow = next(f)
            rows.append([int(x) for x in nextrow.split()])
        print 'Case #{0}: {1}'.format(i, get_missing_row(N, rows))
        i += 1