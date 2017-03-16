from collections import Counter

def solve(j, p, s, k):
    combo = Counter()
    sol = []
    for a in range(1, j + 1):
        for b in range(1, p + 1):
            for c in range(1, s + 1):
                if combo[(0, b, c)] == k or combo[(a, 0, c)] == k or combo[(a, b, 0)] == k:
                    continue

                sol.append((a, b, c))
                combo[(0, b, c)] += 1
                combo[(a, 0, c)] += 1
                combo[(a, b, 0)] += 1

    return sol

def main():
    T = int(input())
    for case_num in range(1, T + 1):
        j, p, s, k = map(int, input().split())
        sol = solve(j, p, s, k)
        print("Case #{0}: {1}".format(case_num, len(sol)))
        for solution in sol:
            print(' '.join(map(str, solution)))

main()
