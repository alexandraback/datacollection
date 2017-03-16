import sys

lines = sys.stdin.readlines()

ntests = int(lines[0])

linenum = 1;
for i in xrange(0, ntests):
    tokens = lines[linenum].split()
    nrows, ncols = int(tokens[0]), int(tokens[1])
    # print nrows, ncols

    rows = [[] for r in xrange(0, nrows)]
    for r in xrange(0, nrows):
        rows[r] = [int(tok) for tok in lines[linenum+1+r].split()]
        # print rows[r]

    cols = [[row[c] for row in rows] for c in xrange(0, ncols)]
    
    # print 
    # print rows
    # print cols
    # print 

    success = True
    for r in xrange(0, nrows):
        if not success:
            break;

        for c in xrange(0, ncols):
            good_row = rows[r][c]>=max(rows[r][0:c]+[0]) and rows[r][c]>=max(rows[r][c+1:]+[0])
            good_col = cols[c][r]>=max(cols[c][0:r]+[0]) and cols[c][r]>=max(cols[c][r+1:]+[0])
            # print r, c, good_row, good_col
            if not (good_row or good_col):
                success = False
                break
 
    if success:
        print "Case #" + str(i+1) + ": YES"
    else:
        print "Case #" + str(i+1) + ": NO"

    linenum = linenum + nrows + 1
