import sys
import math

def howManyMachinas(arminMote, otherMotes):
   otherMotes = sorted(otherMotes)
   
   while len(otherMotes) and arminMote > otherMotes[0]:
      arminMote += otherMotes.pop(0)

   if len(otherMotes) == 0:
      # no modifications needed!
      return 0

   # two options: 
   #  1. remove all motes that are two large
   #  2. add enough motes to eat the next largest one

   remoteMotesSolution = len(otherMotes)
   addMoteSolution = float('inf')

   nextMoteToEat = otherMotes[0]
   assert nextMoteToEat >= arminMote
   if nextMoteToEat - 1 > 0 and arminMote - 1 > 0:
      # can add motes to solve this
      newMotesToAdd = int(math.ceil(math.log(nextMoteToEat - 1, 2) - math.log(arminMote - 1, 2)))
      newArminMote = (2**newMotesToAdd)*(arminMote - 1) + 1
      if newArminMote <= nextMoteToEat:
         newMotesToAdd += 1
         newArminMote = (2**newMotesToAdd)*(arminMote - 1) + 1
      assert newArminMote > nextMoteToEat
      arminMote = newArminMote
      addMoteSolution = newMotesToAdd + howManyMachinas(arminMote, otherMotes)

   return min(addMoteSolution, remoteMotesSolution)

def main():
   lines = open(sys.argv[1], 'r').read().split("\n")
   testCases = lines.pop(0)
   testCases = int(testCases)

   for i in range(testCases):
      A, N = [ int(n) for n in lines.pop(0).split() ]
      moteSizes = [ int(n) for n in lines.pop(0).split() ]
      assert len(moteSizes) == N       
      status = howManyMachinas(A, moteSizes)
      print "Case #%s: %s" % ( i+1, status )

if __name__ == "__main__":
   main()
