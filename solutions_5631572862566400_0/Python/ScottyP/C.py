#!/usr/local/bin/python2.7

import sys

def readint(): return int(raw_input())
def readarray(f): return map(f, raw_input().split())

def dfs(start, visited, graph):
    # print(best) ##
    # print(start) ##
    # print(visited) ##
    # print('') ##
    if graph[start] == []:
        return 1
    else:
        visited.add(start)
        best_score = 0
        for kid in graph[start]:
            if not (kid in visited):
                score = dfs(kid, visited, graph)
                if score > best_score:
                    best_score = score
        return 1 + best_score

_T = readint()
for _t in range(_T):

    forward = {}
    back = {}

    N = readint()
    kids = readarray(int)
    for i in range(N):
        if not ((i + 1) in back):
            back[i + 1] = []
        forward[i + 1] = kids[i]
        if not (kids[i] in back):
            back[kids[i]] = []
        back[kids[i]].append(i + 1)

    # find biggest single
    biggest_single = 0
    been = set()
    for i in range(1, N + 1):
        if i in been:
            continue
        size = 1
        curr = i
        been.add(curr)
        this_been = set([curr])
        while True:
            curr = forward[curr]
            if not (curr in been):
                size += 1
                been.add(curr)
                this_been.add(curr)
            else:
                if size > biggest_single:
                    if curr in this_been:
                        biggest_single = size
                break

    # find pairs
    list_of_pairs = []
    for i in range(1, N + 1):
        if forward[forward[i]] == i and i < forward[i]:
            list_of_pairs.append([i, forward[i]])


    res = 2*len(list_of_pairs)
    for pair in list_of_pairs:
        res += dfs(pair[0], set([pair[1]]), back) - 1
        # print(dfs(0, pair[0], set([pair[1]]), back))
        res += dfs(pair[1], set([pair[0]]), back) - 1
        # print(dfs(0, pair[1], set([pair[0]]), back))

    res = max(res, biggest_single)

    print 'Case #%i:'%(_t+1), res
    sys.stdout.flush()
