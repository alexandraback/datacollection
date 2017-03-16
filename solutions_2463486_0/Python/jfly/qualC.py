import sys

def isPalindrome(n):
   return str(n)[::-1] == str(n)

def analyzeBoundNaive(lower, upper):
   fairAndSquares = []
   for i in range(lower, upper+1):
      if isPalindrome(i):
         sqrt = int(i**.5)
         if sqrt*sqrt == i and isPalindrome(sqrt):
            fairAndSquares.append(i)

   return len(fairAndSquares)


def main():
   lines = open(sys.argv[1], 'r').read().split("\n")
   testCases = lines.pop(0)
   testCases = int(testCases)

   for i in range(testCases):
      lower, upper = lines.pop(0).split(" ")
      lower = int(lower)
      upper = int(upper)
      status = analyzeBoundNaive(lower, upper)
      print "Case #%s: %s" % ( i+1, status )

if __name__ == "__main__":
   main()
