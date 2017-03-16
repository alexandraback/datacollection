from itertools import combinations

def solve(topics):
    for i in range(1, len(topics)):
        for original in map(set, combinations(range(len(topics)), i)):
            first, second = set(), set()
            for j in original:
                first.add(topics[j][0])
                second.add(topics[j][1])
            fake = set(range(len(topics))) - original
            if all(topics[j][0] in first and topics[j][1] in second for j in fake):
                return len(topics) - i
    return 0

output = 'Case #{}: {}'
t = int(input())
for i in range(t):
    n, topics = int(input()), []
    for _ in range(n):
        first, second = input().split()
        topics.append((first, second))
    print(output.format(i + 1, solve(topics)))
