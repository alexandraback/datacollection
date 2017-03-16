# Solution to "Standing Ovation" for Google Code Jam 2015
# by Peter Mattsson (quantum.caffeine@gmail.com)
import sys

def solve(maxShy, people):
    extra, current = 0, 0
    for required, new in enumerate(people):
        if required > current:
            needed = required - current
            extra += needed
            current += needed
        current += int(new)
    return extra

def cases():
    with open(sys.argv[1], 'r') as infile:
        numCases = int(infile.readline())
        for _ in range(numCases):
            maxShy, people = infile.readline().split()
            yield maxShy, people

def main():
    with open(sys.argv[2], 'w') as outfile:
        for caseNo, case in enumerate(cases()):
            outfile.write("Case #%d: %s\n"%(caseNo + 1, str(solve(*case))))

if __name__ == "__main__":
    main()
