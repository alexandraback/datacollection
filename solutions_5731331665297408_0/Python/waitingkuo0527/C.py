def solve(N, M, zips, flights, F):
    """ solve the problem """

    if N == 1: return str(zips[0])

    root_zip = min(zips)
    root = zips.index(root_zip)

    #print(flights)

    for i, adjs in flights.items():
        if i != root and root in adjs: adjs.remove(root)

    #print(flights)

    reached = set([root])
    unreached = set(i for i in range(N)) - reached
    #print(flights)
    reachable = set(i for i in flights[root])
    path = str(zips[root])
    #print(zips, flights)

    #print(root)
    #print(reached)
    #print(unreached)
    #print(reachable)
    #print(path)
    #exit()

    stack = [root]

    #print('flights')
    #print(flights)
    while stack:
        #print()
        node = stack[-1]
        #print(node)
        cur_reachable = flights[node] - reached
        reachable = reachable.union( cur_reachable ) - reached
        if len(reachable) == 0: break
        #print('reachable', reachable)
        #overall_min_zip = min(zips[i] for i in reachable)
        #overall_min_index = zips.index(overall_min_zip)
        overall_zips = [zips[i] for i in reachable]
        overall_zips.sort()
        to_continue = False
        for z in overall_zips:
            index = zips.index(z)
            if index in cur_reachable:
                #print(index)
                #print('---')
                
            #if overall_min_index in cur_reachable:
                #next = overall_min_index
                #path += str(overall_min_zip)
                next = index
                path += str(z)

                reached.add(next)
                reachable.remove(next) 
                stack.append(next)
                #for i, adjs in flights.items():
                #    if i != next and next in adjs: adjs.remove(next)
                to_continue = True
                break
        if to_continue: continue

        #print('check need')
        #print(cur_reachable)
        need_to_reach = set([])
        for v in cur_reachable:
            if len(flights[v]) == 0: 
                #print(v, flights[v])
                raise Exception('woo' + str(v))
            if len(flights[v]) == 1: need_to_reach.add(v)
        #print('need', need_to_reach)
        if need_to_reach:
            _min_zip = min(zips[i] for i in need_to_reach)
            _min_index = zips.index(_min_zip)
            next = _min_index
            path += str(_min_zip)

            reached.add(next)
            reachable.remove(next) 
            stack.append(next)
            #for i, adjs in flights.items():
            #    if i != next and next in adjs: adjs.remove(next)
            continue
        
        for v in cur_reachable:
            if node in flights[v]: flights[v].remove(node)

        stack.pop(-1)

    return path


def parse():
    """ parse input """

    N, M = map(int, input().split(' '))

    zips = [input() for i in range(N)]
    #zips_map = {i: z for i, z in enumerate(zips)}
    flights = {}
    F = {}
    for i in range(N):
        F[i] = {}
        for j in range(N):
            F[i][j] = 0
    #print(F)

    for i in range(M):
        a, b = map(int, input().split(' '))
        a-=1
        b-=1
        if a not in flights: flights[a] = set()
        flights[a].add(b)
        if b not in flights: flights[b] = set()
        flights[b].add(a)
        F[a][b] = 1
        F[b][a] = 1
    
    #print(F)

    return N, M, zips, flights, F


def main():
    
    T = int(input())

    # solve
    for t in range(1, T+1):
        params = parse()
        #if t != 3: continue
        result = solve(*params)
        print('Case #%d: %s' % (t, result))


if __name__ == '__main__':

    main()
