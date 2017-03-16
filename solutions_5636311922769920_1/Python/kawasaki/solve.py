T = int(raw_input())
for t in xrange(T):
    K, C, S = map(int, raw_input().split())
    answer = None
    if S * C < K:
        answer = 'IMPOSSIBLE'
    elif K == 1:
        answer = 1
    elif C == 1:
        answer = ' '.join(str(i + 1) for i in xrange(K))
    else:
        answer = []
        cursor = 0
        while cursor < K:
            ids = [x % K for x in xrange(cursor, cursor + C)]
            answer.append(sum(K ** i * ids[i] for i in xrange(C)) + 1)
            cursor += C
        answer.sort()
        answer = ' '.join(map(str, answer))

    print 'Case #{}: {}'.format(t + 1, answer)
