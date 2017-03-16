from itertools import groupby

class Pancake:
    def flip(self, flipPoint):
        theFlipped = self.pancakes[:flipPoint + 1]
        theFlipped.reverse()
        for x in range(len(theFlipped)):
            theFlipped[x] = not theFlipped[x]
        self.pancakes[:flipPoint + 1] = theFlipped
    
    def neededForAllHappy(self):
        flips = len(self.pancakes) - 1
        if self.pancakes[len(self.pancakes) - 1] == False:
            flips += 1
        return flips
        
    def __init__(self, pancakeString):
        #http://stackoverflow.com/questions/10072744/remove-repeating-characters-from-words
        stackedPancakes = ''.join(c for c, _ in groupby(pancakeString))
        self.pancakes = []
        for x in range(len(stackedPancakes)):
            if stackedPancakes[x] == '+':
                self.pancakes.append(True)
            elif stackedPancakes[x] == '-':
                self.pancakes.append(False)
            else:
                print "ERROR ERROR"

def main():
    cases = int(raw_input())
    for x in range(1, 1 + cases):
        thatString = raw_input()
        pancakeStack = Pancake(thatString)
        flipsNeeded = pancakeStack.neededForAllHappy()
        print("Case #%s: %s" % (x, flipsNeeded))

main()