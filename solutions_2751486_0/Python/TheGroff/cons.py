#!/usr/bin/env python

import sys
from collections import namedtuple

Chest = namedtuple( "chest", [ 'id', 'key', 'contents' ] )
State = namedtuple( "state", [ 'cost', 'done', 'keys', 'chests', 'ct' ] )

cons = set( [ chr(i) for i in range( ord('a'), ord('z') + 1 ) if chr(i) not in ( 'a', 'e', 'i', 'o', 'u' ) ] )

def solve( word, nc ):
  tw = 0
  found = set()
  for i in range( len( word ) - nc + 1 ):
    ok = True
    for j in range( nc ):
      if word[i+j] not in cons:
        ok = False
        break
    if not ok:
      continue
    for l in range( i + 1):
      for r in range( i + nc - 1, len( word ) ):
        sw = ( l, r )
        if sw not in found:
          found.add( sw )
          tw += 1
  return tw


def solve2( word, nc ):
  tw = 0
  mini = -1
  #print( "WORD", word, nc )
  for i in range( len( word ) - nc + 1 ):
    ok = True
    for j in range( nc ):
      if word[i+j] not in cons:
        ok = False
        break
    if not ok:
      continue
    #print( "Found", word[i:i+nc], i, nc, mini )
    ll = i - ( mini + 1 )
    rl = len( word ) - i - nc
    tw += ( ( ll + 1 ) * ( rl + 1 ) )
    mini = max( mini, ll )


  return tw



if __name__ == '__main__':
  cases = int( sys.stdin.readline().strip() )
  for case in range( cases ):
    name, nc =  sys.stdin.readline().strip().split()
    print( "Case #{}: {}".format( case + 1, solve( name.lower(), int( nc ) ) ) )
