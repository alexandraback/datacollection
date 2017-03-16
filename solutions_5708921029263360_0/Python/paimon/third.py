from collections import Counter

def solve(J, P, S, k):
    result = []
    first, second, third = Counter(), Counter(), Counter()
    for j in range(J):
        for p in range(P):
            for s in range(S):
                if first[j, p] < k and second[j, s] < k and third[p, s] < k:
                    result.append((j + 1, p + 1, s + 1))
                    first[j, p] += 1
                    second[j, s] += 1
                    third[p, s] += 1
    return result

output = 'Case #{}: {}'
num_tests = int(input())
for i in range(num_tests):
    J, P, S, k = map(int, input().split())
    result = solve(J, P, S, k)
    print(output.format(i + 1, len(result)))
    for j, p, s in result:
        print(j, p, s)
