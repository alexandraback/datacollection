#!/usr/bin/env python


import logging
logging.basicConfig(level=logging.INFO,
    format='%(asctime)s %(name)s %(levelname)s %(message)s',
    datefmt='%H:%M:%S')
logger = logging.getLogger( 'main' )



def get_missing_row( rowlen, rowcol_lines ):
    logger.info( 'rowlen: %d', rowlen )
    hcnts = dict()
    for line in rowcol_lines:
        line = line.strip()
        row = list()
        for height in line.split( ' ' ):
            height = int(height)
            if height in hcnts:
                hcnts[height] += 1
            else:
                hcnts[height] = 1

    missing_row = list()
    for (h, cnt) in hcnts.iteritems():
        if cnt % 2 == 1:
            missing_row.append( h )

    assert len(missing_row) == rowlen
    missing_row.sort()
    missing_row = [str(h) for h in missing_row]
    res = ' '.join( missing_row )
    return res



import sys

if __name__ == '__main__':
    filename_prefix = sys.argv[1]
    filename_in = filename_prefix + ".in"
    filename_out = filename_prefix + ".out"

    file_in = open( filename_in, 'r' )
    lines = file_in.readlines()
    file_in.close()

    testcnt = int(lines[0])
    file_out = open( filename_out, 'w' )

    idx = 1
    for test in range( 1, testcnt + 1 ):
        rowlen = int( lines[idx] )
        idx += 1
        res = get_missing_row( rowlen, lines[idx:(idx + 2*rowlen - 1)] )
        idx += (2*rowlen - 1)
        logger.info( "Case #%d: %s", test, res )
        file_out.write( "Case #{0}: {1}\n".format(test, res) )

    file_out.close()
