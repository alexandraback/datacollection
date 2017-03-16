#!/usr/bin/env python


def nValue( name, n ):
   l = len( name )
   result = 0
   start = 0
   while start <= l - n:
      consecutive = 0
      end = start
      while end < l:
         if name[ end ] not in [ 'a', 'e', 'i', 'o', 'u' ]:
            consecutive += 1
            if consecutive >= n:
               result += l - end
               break
         else:
            consecutive = 0
         end += 1
      start += 1
   return result

if __name__ == "__main__":
   T = int( raw_input() )
   for i in range( 0, T ):
      nameAndN = raw_input().split()
      name = nameAndN[ 0 ]
      n = int( nameAndN[ 1 ] )
      print "Case #%d: %d" % ( i + 1, nValue( name, n ) )
