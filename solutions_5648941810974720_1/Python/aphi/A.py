from sys import stdin, stdout
from collections import defaultdict

words = ("ZERO", "TWO", "SIX", "SEVEN", "FIVE", "FOUR", "ONE", "THREE", "EIGHT", "NINE")
nums = ("0", "2", "6", "7", "5", "4", "1", "3", "8", "9")
wordDicts = []

for w in words:
    wordDicts.append( dict((ch, w.count(ch)) for ch in set(w)) )

def solve(S):
    counts = defaultdict(int)
    for s in S:
        counts[s] += 1

    numbers = []

    for i, wDict in enumerate(wordDicts):

        more = True
        while more:
            more = False
            if all(counts[letter] >= wDict[letter] for letter in wDict):
                # add
                for letter in wDict:
                    counts[letter] -= wDict[letter]

                numbers.append(nums[i])

                more = True
    
    if any(count != 0 for count in counts.values()):
        raise RuntimeError, "Unassigned Letters"

    return "".join(sorted(numbers))


T = int(stdin.readline())

for t in range(T):
    S = stdin.readline().strip()

    result = solve(S)

    stdout.write("Case #%d: %s\n"%(t+1, result))