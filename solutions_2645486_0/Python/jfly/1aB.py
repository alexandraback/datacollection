import sys

def bestEnergy(maxEnergy, recoverEnergy, activities):
   fringe = [ ( maxEnergy, activities, [] ) ]
   solutions = []
   while fringe:
      node = fringe.pop()
      currEnergy, remainingActivities, path = node
      remainingActivities = remainingActivities[:]
      if len(remainingActivities) == 0:
         # we're done, sum up our path
         solutions.append(path)
      else:
         activity = remainingActivities.pop()
         spendRange = None
         if len(remainingActivities) == 0:
            # BLOW OUR LOAD, THERE IS NOTHING LEFT
            spendRange = [ currEnergy ]
         else:
            # we can spend anywhere in the range [R, currEnergy] here
            if currEnergy < recoverEnergy:
               spendRange = [ currEnergy ] # we'll make it all back
            else:
               #<<<spendRange = range(recoverEnergy, currEnergy + 1)
               spendRange = range(0, currEnergy + 1)

         for energyToSpend in spendRange:
            nextEnergy = min(maxEnergy, currEnergy - energyToSpend + recoverEnergy)
            assert nextEnergy >= 0
            fringe.append((nextEnergy, remainingActivities, path + [energyToSpend]))

   gainSolutions = [ sum([ spent*activity for spent, activity in zip(solution, activities) ]) for solution in solutions ]
   return max(gainSolutions)

def main():
   lines = open(sys.argv[1], 'r').read().split("\n")
   testCases = lines.pop(0)
   testCases = int(testCases)

   for i in range(testCases):
      E, R, N = [ int(n) for n in lines.pop(0).split(" ") ]
      activities = [ int(n) for n in lines.pop(0).split(" ") ]
      assert len(activities) == N

      status = bestEnergy(E, R, activities)
      print "Case #%s: %s" % ( i+1, status )

if __name__ == "__main__":
   main()
