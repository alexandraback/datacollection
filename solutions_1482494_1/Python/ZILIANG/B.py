
T = input()

for t in range(T):
    N = input()
    ones = []
    twos = []
    for n in range(N):
        a, b = map(int, raw_input().split())
        ones.append(a)
        twos.append(b)

    one_to_play = set(range(N))
    two_to_play = set(range(N))

    result = [0] * N
    s = 0
    ans = 0
    
    ok = True
    while ok:
        ok = False
# play 2 stars
        to_remove = []
        for i in two_to_play:
            if s >= twos[i] and result[i] < 2:
                ok = True
                s += 2 - result[i]
                result[i] = 2
                ans += 1
                #two_to_play.remove(i)
                to_remove.append(i)
        for i in to_remove:
            two_to_play.remove(i)

        if ok: continue

# play 1 star
        to_remove = -1
        hardest = -1
        for i in one_to_play:
            if s >= ones[i] and result[i] < 1:
                if twos[i] > hardest:
                    ok = True
                    hardest = twos[i]
                    #one_to_play.remove(i)
                    to_remove = i



        if to_remove != -1:
            ok = True
            s += 1 - result[to_remove]
            result[to_remove] = 1
            ans += 1
            one_to_play.remove(to_remove)


    print 'Case #%d:' % (t+1), sum(result) == N * 2 and ans or 'Too Bad'


