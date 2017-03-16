#!/usr/bin/env python

from sys import stdin

def game_over(B):
   return all( [ B[r][c] != '.' for r in xrange(4) for c in xrange(4) ] )

def is_winner(player, B):
   for r in xrange(4):
      if all( [ B[r][c] == player or B[r][c] == 'T' for c in xrange(4) ] ):
         return True
   for c in xrange(4):
      if all( [ B[r][c] == player or B[r][c] == 'T' for r in xrange(4) ] ):
         return True
   if all( [ B[i][i] == player or B[i][i] == 'T' for i in xrange(4) ] ):
      return True
   if all( [ B[i][3-i] == player or B[i][3-i] == 'T' for i in xrange(4) ] ):
      return True
   return False

def get_state(B):
   if is_winner('X', B): return "X won"
   if is_winner('O', B): return "O won"
   return "Draw" if game_over(B) else "Game has not completed"

def main():
   TC = int(stdin.readline().strip())
   for tc in xrange(1, TC+1):
      B = []
      for r in xrange(4):
         B.append( stdin.readline().strip() )
      stdin.readline()
      print "Case #%d: %s" % (tc, get_state(B))
   return 0

if __name__ == '__main__': main()
