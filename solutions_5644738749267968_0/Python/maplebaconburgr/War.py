'''
Created on Apr 11, 2014

@author: dbaron
'''
def main():
   f = open('D-small-attempt0.in', 'r')
   g = open('WarResults.txt', 'w')
   done = False
   T = int(readLine(f))
   for testCase in range(1, T+1):
      readLine( f )
      n = sorted(readFloatArray(f))
      k = sorted(readFloatArray(f))
      normalResult = doNormal( n[:], k[:] )
      cheatResult = doCheat( n[:], k[:] )
      g.write( "Case #%d: %d %d\n" % (testCase, cheatResult, normalResult))
      print "Case #%d: %d %d" % (testCase, cheatResult, normalResult)
      
def doNormal( n, k ):
   score = 0
   while len(n) > 0:
      bestN = n[-1]
      n = n[:-1]
      bestK = k[-1]
      if bestN > bestK:
         score += 1
         k = k[1:]
      else:
         k = k[:-1]
   return score

def doCheat( n, k ):
   score = 0
   while len(n) > 0:
      worstN = n[0]
      worstK = k[0]
      if worstN > worstK:
         score += 1
         n = n[1:]
         k = k[1:]
      else:
         n = n[1:]
         k = k[:-1]
   return score

def readFloatArray( f ):
   return map( float, readLine(f).split() )

def readIntArray( f ):
   return map( lambda x: int(x[2:]), readLine(f).split() )

def readLine( f ):
   return f.readline().rstrip('\n')

if __name__ == '__main__':
    main()