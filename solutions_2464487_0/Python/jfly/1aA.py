import sys

def howManyRings(r, t):
   # want to find when
   #  [ (r+1)**2 - r**2 ] + [ (r+3)**2 - (r+2)**2 ] + ... 
   # gets bigger than t

   rings = 0
   total = 0
   while True:
      total += (r + 2*rings + 1)**2 - (r + 2*rings)**2
      rings += 1
      if total > t:
         return rings - 1

def main():
   lines = open(sys.argv[1], 'r').read().split("\n")
   testCases = lines.pop(0)
   testCases = int(testCases)

   for i in range(testCases):
      r, t = lines.pop(0).split(" ")
      r = int(r)
      t = int(t)
      status = howManyRings(r, t)
      print "Case #%s: %s" % ( i+1, status )

if __name__ == "__main__":
   main()
