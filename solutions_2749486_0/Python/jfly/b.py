import sys

unsolved = set(range(100+1))
addUpTo = {} # for each number, has a mapping of count to solution
fringe = [ (0, []) ]
while unsolved:
   val, path = fringe.pop(0)
   unsolved.discard(val)
   count_to_solution = addUpTo.get(val, {})
   addUpTo[val] = count_to_solution
   count_to_solution[len(path)] = path

   delta = len(path) + 1
   for sign in [ -1, 1 ]:
      newVal = val + sign*delta
      newPath = path + [ sign*delta ]

      count_to_solution = addUpTo.get(newVal, {})
      addUpTo[newVal] = count_to_solution
      count_to_solution[len(newPath)] = newPath

      fringe.append((newVal, newPath))
      unsolved.discard(newVal)

for num, sols in addUpTo.iteritems():
   for length, sol in sols.iteritems():
      assert length == len(sol)
      assert num == sum(sol)

unsolved = set()
for x in range(-100, 100+1):
   for y in range(-100, 100+1):
      if x == 0 and y == 0:
         continue
      unsolved.add((x, y))

directions = {
   "N": (0, 1),
   "S": (0, -1),
   "E": (1, 0),
   "W": (-1, 0)
}

solved = {}
def addSolution(pos, path):
   if pos not in solved:
      solved[pos] = path
   unsolved.discard(pos)

fringe = [ ((0, 0), "") ]
while unsolved:
   pos, path = fringe.pop(0)
   #print len(path), len(unsolved)#<<<
   addSolution(pos, path)

   delta = len(path) + 1
   for direction, unit in directions.iteritems():
      newPath = path + direction
      newX = pos[0] + delta*unit[0]
      newY = pos[1] + delta*unit[1]
      newPos = (newX, newY)
      if newPos in solved:
         continue
      #if abs(newPos[0]) > 100 or abs(newPos[1]) > 100:
         # do you have to step out and then back in?
         #continue
      if len(unsolved) <= 24:
         for num, sols in addUpTo.iteritems():
            #<<<
            solutionPosX = []
            solutionNegX = []
            solutionPosY = []
            solutionNegY = []
            for i, step in enumerate(sols[sols.keys()[0]]):
               solutionPosX.append("E" if step > 0 else "W")
               solutionNegX.append("W" if step > 0 else "E")
               solutionPosY.append("N" if step > 0 else "S")
               solutionNegY.append("S" if step > 0 else "N")
            addSolution((num, 0), solutionPosX)
            addSolution((-num, 0), solutionNegX)
            addSolution((0, num), solutionPosY)
            addSolution((0, -num), solutionNegY)
      addSolution(newPos, newPath)
      fringe.append((newPos, newPath))

for k, v in solved.iteritems():
   assert len(v) <= 500


def main():
   lines = open(sys.argv[1]).read().split("\n")
   T = int(lines.pop(0))
   for i in range(T):
      X, Y = [ int(c) for c in lines.pop(0).split() ]
      status = solved[(X, Y)]
      print "Case #%s: %s" % ( i+1, status )

if __name__ == "__main__":
   main()
