# -*- coding: utf-8 -*-

import sys


gDbgLvl = 0
maxLvl = 0

cannedInput = 0

def main():   
  
  
  T = int(sys.stdin.readline())        

  logMsg("T = " + str(T))
  
  for t in range(1, T+1):
      

      line = (sys.stdin.readline())    
      testCase = line.split('/');

      P = long(testCase[0])
      Q = long(testCase[1])

      logMsg("P = " + str(P) + " Q = " + str(Q))

      den = long(2)
      ok = False
      
      for x in range(1, 41):
          num = P * den
          if (num % Q) == 0:
              num = num // Q
              ok = True
              break
          den *= 2


      if (ok):
          P = num
          Q = den
          logMsg("x = " + str(x) + " num = " + str(num) + " den = " + str(den))
          answer = x

          elfPart = Q // 2
          for y in range(1, x+1):
             logMsg("y = " + str(y) + " elfPart = " + str(elfPart))
             if (P >= elfPart):
                 answer = y
                 break
             elfPart = elfPart // 2

      else:
          answer = "impossible"

      print("Case #" + str(t) + ": " + str(answer))



def countOnes(x):
    count = 0
    while (x != 0):
        if (x % 2 == 1):
            count = count + 1
        x = x // 2
    return count
    

def minGen(P, Q):
      den = long(2)
      ok = False
      for x in range(1, 41):
          num = P * den
          if (num % Q) == 0:
              num = num // Q
              ok = True
              break
          den *= 2
     
      if ok:
          return x
      else:
          return -1

def logMsg(str, lvl = 1):
    if (gDbgLvl >= lvl):
      print(str);


main()