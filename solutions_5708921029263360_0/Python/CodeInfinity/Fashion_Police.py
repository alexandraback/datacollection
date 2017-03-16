from itertools import product
from collections import defaultdict

if __name__ == '__main__':
    for i in range(1, int(input()) + 1):
        J, P, S, K = map(int, input().split())
        JP, JS, PS = defaultdict(int), defaultdict(int), defaultdict(int)
        ans = []
        for t in product(range(1, J + 1), range(1, P + 1), range(1, S + 1)):
            t1, t2, t3 = t
            if JP[(t1, t2)] == K:
                continue
            if JS[(t1, t3)] == K:
                continue
            if PS[(t2, t3)] == K:
                continue

            ans.append(t)
            JP[(t1, t2)] += 1
            JS[(t1, t3)] += 1
            PS[(t2, t3)] += 1

        print("Case #", i, ": ", len(ans), sep = '')
        for t in ans:
            print(*t)
