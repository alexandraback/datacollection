#!/usr/bin/env python


# This breaks the 2-dimensional pogo problem into 2 1-dimensional portions.
# Most likely, this approach won't yield minimum hop results but this should
# be good enough for providing hop counts well below 500.
def hopSequence( x, y ):
   sequence = []
   currentX = 0
   currentY = 0
   hopSize = 1
   if currentX != x:
      ( currentX, count ) = approach( x, hopSize )
      hopSize += count
      if x > 0:
         for i in range( 0, count ):
            sequence.append( "E" )
      else:
         for i in range( 0, count ):
            sequence.append( "W" )
      if currentX != x:
         oscillateSeq = oscillate( currentX, x, hopSize )
         hopSize += len( oscillateSeq )
         for hop in oscillateSeq:
            if hop > 0:
               sequence.append( "E" )
            else:
               sequence.append( "W" )
   if currentY != Y:
      ( currentY, count ) = approach( y, hopSize )
      hopSize += count
      if y > 0:
         for i in range( 0, count ):
            sequence.append( "N" )
      else:
         for i in range( 0, count ):
            sequence.append( "S" )
      if currentY != y:
         oscillateSeq = oscillate( currentY, y, hopSize )
         hopSize += len( oscillateSeq )
         for hop in oscillateSeq:
            if hop > 0:
               sequence.append( "N" )
            else:
               sequence.append( "S" )
   return "".join( sequence )


# Quick and direct approach to the target position
def approach( goal, hopSize ):
   count = 0
   current = 0
   if goal > 0:
      hopDir = 1
   else:
      hopDir = -1
   goalMagnitude = abs( goal )
   while abs( current + hopDir * hopSize ) <= goalMagnitude:
      current += hopDir * hopSize
      hopSize += 1
      count += 1
   return ( current, count )


# For fine tuning the position
def oscillate( start, goal, hopSize ):
   sequence = []
   current = start
   # Move farther from the goal first.
   if goal > current:
      hopDir = -1
   else:
      hopDir = 1
   # Keep hopping back and forth until the goal position is reached.
   while current != goal:
      current += hopDir * hopSize
      hopSize += 1
      sequence.append( hopDir )
      # Reverse direction after each hop.
      hopDir = -hopDir
   return sequence


if __name__ == "__main__":
   T = int( raw_input() )
   for i in range( 0, T ):
      XandY = raw_input().split()
      X = int( XandY[ 0 ] )
      Y = int( XandY[ 1 ] )
      print "Case #%d: %s" % ( i + 1, hopSequence( X, Y ) )
