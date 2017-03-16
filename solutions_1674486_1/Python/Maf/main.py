#!/usr/bin/env python3

def get(conv):
    return conv(input())

def getv(conv):
    line = input().split(' ')
    return list(map(conv, line[1:]))

T = get(int)
for t in range(T):
    ans = 'No'
    N = get(int)
    graph = dict()
    for n in range(N):
        others = getv(int)
        graph[n+1] = others
    
    for n in range(N):
        visited = [False] * N
        queue = []
        queue.append(n+1)
        while len(queue):
            a = queue.pop()
            if visited[a-1]:
                ans = 'Yes'
                break
            visited[a-1] = True
            for b in graph[a]:
                queue.append(b)

        if ans == 'Yes':
            break
    
    print("Case #{}: {}".format(t+1, ans))
