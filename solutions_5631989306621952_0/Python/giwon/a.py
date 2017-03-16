#!/usr/bin/env python


import logging
logging.basicConfig(level=logging.INFO,
    format='%(asctime)s %(name)s %(levelname)s %(message)s',
    datefmt='%H:%M:%S')
logger = logging.getLogger( 'main' )



def get_biggest_word( line ):
    line = line.strip()
    initial_word = line

    word = initial_word[0]
    for ch in initial_word[1:]:
        if ch >= word[0]:
            word = ch + word
        else:
            word = word + ch
    return word



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
        res = get_biggest_word( lines[idx] )
        logger.info( "Case #%d: %s", test, res )
        file_out.write( "Case #{0}: {1}\n".format(test, res) )
        idx += 1

    file_out.close()
