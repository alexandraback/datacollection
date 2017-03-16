#!/usr/bin/env python3

def solve(n):
    bffs = list(map(lambda x: int(x)-1, input().split()))

    used = [False] * n
    circles = [False] * n

    best = 0

    def mark(i, p, c):
        while not circles[i]:
            circles[i] = {'circle': c, 'path': p}
            i = bffs[i]
            #p -= 1
            p = p[1:]

    def follow(i, force=False):
        kid = i
        p = [kid]
        used[kid] = True
        while True:
            kid = bffs[kid]
            if kid == i:
                #circle
                for x in p:
                    circles[x] = {'circle': p, 'path': []}
                return p
            if not force and used[kid]:
                if circles[kid]:
                    mark(i, p + circles[kid]['path'], circles[kid]['circle'])
                    return
                else:
                    nodes = follow(kid, force=True)
                    nodes_set = set(nodes)
                    path = []
                    for n in p:
                        if n in nodes_set:
                            break
                        path.append(n)

                    mark(i, path, nodes)
                    return nodes
                #return
            used[kid] = True
            p.append(kid)

    def find(friend, exclude):
        for i in range(n):
            if bffs[i] == friend and i not in exclude:
                return True
        return False

    for i in range(n):
        if used[i]:
            continue
        follow(i)

    #best = 0
    #print(circles)

    uniq = [False] * n

    for c in circles:
        x = min(c['circle'])
        if not uniq[x]:
            uniq[x] = c
        else:
            if len(c['path']) > len(uniq[x]['path']):
                uniq[x] = c
    uc = []
    for u in uniq:
        if u:
            uc.append(u)

    #print(uc)

    exclude = set()
    l = 0
    c2 = []
    for c in uc:
        if len(c['circle']) == 2:
            exclude.update(c['circle'])
            exclude.update(c['path'])
            l += 2 + len(c['path'])
            c2.append(c)

    for c in c2:
        if c['path']:
            last = c['path'][-1]
            s = set(c['circle'])
            s.remove(bffs[last])
            lastc = list(s)[0]
            if find(lastc, exclude):
                l += 1

    best = l

    for c in uc:
        if len(c['circle']) == 2:
            l = 2 + len(c['path'])
            if c['path']:
                last = c['path'][-1]
                s = set(c['circle'])
                s.remove(bffs[last])
                lastc = list(s)[0]
                exclude = set(c['circle'])
                exclude.update(c['path'])
                #print("FIND friend of %s, out of %s, res %s" % (lastc, exclude, find(lastc, exclude)))
                if find(lastc, exclude):
                    l += 1
            # else:
            #     exclude = set(c['circle'])
            #     if find(c['circle'][0], exclude) or find(c['circle'][1], exclude):
            #         l += 1
        else:
            l = len(c['circle'])
        if l > best:
            best = l
    return best


testcases = int(input())

for case_n in range(1, testcases+1):
    case_data = map(int, input().split())
    #case_data = input().split()
    print("Case #%i: %s" % (case_n, solve(*case_data)))
