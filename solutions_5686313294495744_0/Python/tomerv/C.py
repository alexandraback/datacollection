from collections import defaultdict
from itertools import permutations


def solve(tc):
    counts = [defaultdict(int),defaultdict(int)]
    for topic in tc:
        counts[0][topic[0]] += 1
        counts[1][topic[1]] += 1
    ordered = []
    rem = []
    seen = [defaultdict(int),defaultdict(int)]
    # uniques
    for topic in tc:
        if counts[0][topic[0]] == 1 or counts[1][topic[1]] == 1:
            ordered.append(topic)
            seen[0][topic[0]] += 1
            seen[1][topic[1]] += 1
        else:
            rem.append(topic)
    #print(ordered, rem)
    # firsts on both
    rem1 = []
    for topic in rem:
        if not seen[0][topic[0]] and not seen[1][topic[1]]:
            ordered.append(topic)
            seen[0][topic[0]] += 1
            seen[1][topic[1]] += 1
        else:
            rem1.append(topic)
    #print(ordered, rem1)
    # firsts on one
    rem2 = []
    for topic in rem1:
        if not seen[0][topic[0]] or not seen[1][topic[1]]:
            ordered.append(topic)
            seen[0][topic[0]] += 1
            seen[1][topic[1]] += 1
        else:
            rem2.append(topic)
    #print(ordered, rem2)
    return len(rem2)

t = int(input())
for i in range(t):
    n = int(input())
    tc = []
    for j in range(n):
        tc.append(tuple(input().split()))
    sol = solve(tc)
    print('Case #{}: {}'.format(i+1, sol))
