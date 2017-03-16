import sys

def isPalindrome(n):
   return str(n)[::-1] == str(n)

def palindromes(upperLength):
   palsByLength = []
   palsByLength.append([]) # length 0
   palsByLength.append(range(1, 10)) # length 1 (note that we skip 0)
   for length in range(len(palsByLength), upperLength + 1):
      prevPals = palsByLength[length - 1]
      nextPals = []
      for pal in prevPals:
         pal = str(pal)
         assert len(pal) == length - 1
         midway = len(pal)/2
         if len(pal) % 2 == 0:
            # we can put anything we like in the middle
            for digit in range(10):
               newPal = pal[:midway] + str(digit) + pal[midway:]
               nextPals.append(int(newPal))
         else:
            # only thing we can do is duplicate the loner in the middle
            newPal = pal[:midway] + pal[midway] + pal[midway:]
            nextPals.append(int(newPal))

      palsByLength.append(nextPals)

   pals = sum(palsByLength, [])
   return pals

def findFairAndSquares(upto):
   upperSqrt = int(upto**.5)
   upperPalindromeLength = len(str(upperSqrt))
   fairAndSquares = set()
   for palindrome in palindromes(upperPalindromeLength):
      square = palindrome*palindrome
      if isPalindrome(square):
         fairAndSquares.add(square)
   return fairAndSquares

fairAndSquares = findFairAndSquares(10**14)

def isFairAndSquare(i):
   return i in fairAndSquares #<<<
   if isPalindrome(i):
      sqrt = int(i**.5)
      if sqrt*sqrt == i and isPalindrome(sqrt):
         return True
   return False

def analyzeBoundNaive(lower, upper):
   found = []
   """for i in range(lower, upper+1):
      if isFairAndSquare(i):
         found.append(i)
         """
   for fairAndSquare in fairAndSquares:
      if lower <= fairAndSquare <= upper:
         found.append(fairAndSquare)

   return len(found)


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
