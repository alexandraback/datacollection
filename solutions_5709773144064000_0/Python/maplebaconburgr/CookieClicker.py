'''
Created on Apr 11, 2014

@author: dbaron
'''

def main():
   f = open('B-small-attempt0.in', 'r')
   g = open('CookieClickerkResults.txt', 'w')
   T = int(readLine(f))
   for testCase in range(1, T+1):
      input = readFloatArray( f )
      result = operate( input[0], input[1], input[2] )
      g.write( "Case #%d: %s\n" % (testCase, result))
      print "Case #%d: %s" % (testCase, result)
      
def operate( C, F, X ):
   rate = 2
   time = 0
   oldTime = ( X / rate ) + time
   while True:
      time += ( C / rate )
      rate += F
      newTime = ( X / rate ) + time
      if oldTime <= newTime:
         return oldTime
      else:
         oldTime = newTime

def readIntArray( f ):
   return map( int, readLine(f).split() )

def readFloatArray( f ):
   return map( float, readLine(f).split() )

def readLine( f ):
   return f.readline().rstrip('\n')

if __name__ == '__main__':
    main()