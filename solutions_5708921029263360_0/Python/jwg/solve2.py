#google code jam I/O template
import string
import collections

def solve(A, B, C, k):
    outfits = []
    m = min(k, A)
    seenAB = collections.Counter()
    seenAC = collections.Counter()
    seenBC = collections.Counter()
    for a in range(1, A+1):
        for b in range(1, B+1):
            for c in range(1, C+1): 
                if seenAB[(a, b)] < k and seenAC[(a, c)] < k and seenBC[(b, c)] < k:
                    seenAB[(a, b)] += 1
                    seenAC[(a, c)] += 1
                    seenBC[(b, c)] += 1
                    outfits.append("%d %d %d" % (a, b, c))

    return len(outfits), outfits

numCases = input()
for caseNum in range(1, numCases+1):
    #read single-line input
    A, B, C, k = map(int, raw_input().split(" "))
    ans, lst = solve(A, B, C, k)
    print "Case #%d: %d" % (caseNum, ans)
    for line in lst:
        print line





