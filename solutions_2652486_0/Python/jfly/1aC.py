import sys
import itertools
import random

def list_powerset(lst):
    # the power set of the empty set has one element, the empty set
    result = [[]]
    for x in lst:
        # for every additional element in our set
        # the power set consists of the subsets that don't
        # contain this element (just take the previous power set)
        # plus the subsets that do contain the element (use list
        # comprehension to add [x] onto everything in the
        # previous power set)
        result.extend([subset + [x] for subset in result])
    return result

def bestGuess(N, M, products):
   allChoices = itertools.product(*[range(2, M+1)]*N)
   prodToSets = {}
   for choice in allChoices:
      for subset in list_powerset(choice):
         prod = reduce(lambda x, y: x*y, subset, 1)
         #if prod not in prodToSets:
            #prodToSets[prod] = []
         #prodToSets[prod].append(choice)

         if prod not in prodToSets:
            prodToSets[prod] = set()
         prodToSets[prod].add(tuple(sorted(choice)))

   potentialChoices = prodToSets[products[0]]
   for prod in products:
      potentialChoices &= prodToSets[prod]

   choice = random.choice(list(potentialChoices))#<<<
   return sorted(choice)

def main():
   lines = open(sys.argv[1], 'r').read().split("\n")
   testCases = lines.pop(0)
   testCases = int(testCases)

   for i in range(testCases):
      R, N, M, K = [ int(n) for n in lines.pop(0).split(" ") ]

      print "Case #%s:" % ( i+1 )

      for j in range(R):
         products = [ int(n) for n in lines.pop(0).split(" ") ]
         assert len(products) == K
         numbers = bestGuess(N, M, products)
         print "".join(str(num) for num in numbers)

if __name__ == "__main__":
   main()
