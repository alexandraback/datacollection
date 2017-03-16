def solve(N, F):
    """ solve the problem """

    A = {i: set([])for i in range(N)}
    for i, f in enumerate(F):
        A[f].add(i)
    #print(A)

    result = -1
    for beg in range(N):
        cur = beg
        circle = [cur]
        circle_set = set([cur])
        count = 1
        last = -1
        while True:
            next = F[cur]
            if next in circle:
                last = next
                break
            count += 1
            circle_set.add(next)
            circle.append(next)
            cur = next
        result = max(count-circle.index(last), result)

    pairs = []
    for i in range(N):
        for j in range(i+1, N):
            if F[i] == j and F[j] == i:
                pairs.append([i, j])

    all_pairs_count = 0
    #print('pairs:', pairs)
    for pair in pairs:
        all_pairs_count += 2
        count = 0
        _p = set(pair)
        for cur_layer in [set([pair[0]]), set([pair[1]])]:
            done = cur_layer.copy()
            to_add = 0
            while True:
                cur_A = set([])
                for c in cur_layer:
                    cur_A = cur_A.union( A[c] )
                #print('ori cur_A', cur_A)
                cur_A = cur_A.difference(done).difference(_p)
                #print('cur_A', cur_A)
                if len(cur_A) == 0:
                    break
                #print('cur_A', cur_A)
                count += 1
                to_add += 1
                done = done.union(cur_A)
                cur_layer = cur_A
            #print('to_add', to_add)
        all_pairs_count += count

            
    result = max(all_pairs_count, result)

    return result


def parse():
    """ parse input """

    N = int(input())
    F = [int(i)-1 for i in input().split()]

    return N, F


def main():
    
    T = int(input())

    # solve
    for t in range(1, T+1):
        params = parse()
        result = solve(*params)
        print('Case #%d: %s' % (t, result))


if __name__ == '__main__':

    main()
