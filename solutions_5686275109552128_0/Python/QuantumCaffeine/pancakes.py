# Solution to "Infinite House of Pancakes" for Google Code Jam 2015
# by Peter Mattsson (quantum.caffeine@gmail.com)
import sys, heapq

def solve(numDiners, diners):
    heapq.heapify(diners)
    maxsteps = -diners[0]
    best = maxsteps
    for specials in xrange(maxsteps):
        next = heapq.heappop(diners)
        best = min(best, specials - next)
        print next, specials - next
        split = next/2
        heapq.heappush(diners, next - split)
        heapq.heappush(diners, split)
    return best

def cases():
    with open(sys.argv[1], 'r') as infile:
        numCases = int(infile.readline())
        for _ in range(numCases):
            numDiners = int(infile.readline())
            diners = [-int(x) for x in infile.readline().split()]
            yield numDiners, diners

def main():
    with open(sys.argv[2], 'w') as outfile:
        for caseNo, case in enumerate(cases()):
            outfile.write("Case #%d: %s\n"%(caseNo + 1, str(solve(*case))))

if __name__ == "__main__":
    main()
