import collections
import itertools

def solve(N, M, zips, G):
    cur_sol = None
    for seq in itertools.permutations(range(N)):
        sseq = seq[:-1] + tuple(reversed(seq))
        if possible(seq, G, N):
            cat = [zips[i] for i in seq]
            #print(seq)
            result = int(''.join(cat))
            if cur_sol is None or result < cur_sol:
                cur_sol = result
    return cur_sol

def possible(seq, G, N):
    cur = seq[0]
    stack = [cur]
    for u in seq[1:]:
        while u not in G[stack[-1]]:
            stack.pop()
            #print(u, stack)
            if not stack:
                return False
        stack.append(u)
        cur = u
        #print(stack)
    return True
    #edges = zip(seq, seq[1:])
    #return all([v in G[u] for u, v in edges])

def main():
    T = int(input())
    for i in range(1, T + 1):
        N, M = [int(s) for s in input().strip().split()]
        zips = [input() for _ in range(N)]

        G = collections.defaultdict(list)
        for m in range(M):
            e, v = [int(s) for s in input().strip().split()]
            G[e - 1].append(v - 1)
            G[v - 1].append(e - 1)

        #print(N, M, zips, G)
        res = solve(N, M, zips, G)
        print('Case #', i, ': ', res, sep='')

if __name__ == "__main__":
    main()
