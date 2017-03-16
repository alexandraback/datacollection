def findCircle(N, F, index, count, end):
    visited = set()
    visited.add(index)
    end[index] = index
    p = index
    while F[p] not in visited:
        friend = F[p]
        visited.add(friend)
        end[index] = friend
        if F[friend] == p or F[friend] == index:
            count[index] = len(visited)
            return
        p = friend

T = eval(input())

for caseNum in range(T):
    N = eval(input())
    F = [eval(x) for x in input().split()]
    F.insert(0, -1)
    count = [0 for _ in range(N + 1)]
    end = [0 for _ in range(N + 1)]
    for i in range(1, N + 1):
        findCircle(N, F, i, count, end)
    maxCount = max(count)
    maxduple = [0 for _ in range(N + 1)]
    for i in range(1, N + 1):
        if F[F[end[i]]] != end[i]:
            continue
        maxduple[end[i]] = max(maxduple[end[i]], count[i])
    newMax = sum(maxduple)
    for i in range(1, N + 1):
        if maxduple[i] > 0 and maxduple[F[i]] > 0:
            newMax -= 1
    maxCount = max(maxCount, newMax)
    print('Case #{}: {}'.format(caseNum + 1, maxCount))
