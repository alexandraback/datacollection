d = int(raw_input())

for i in range(1, d+1):
    print 'Case #' + str(i) + ':',
    k, c, s = map(int, raw_input().split())
    if s * c < k:
        print 'IMPOSSIBLE'
        continue
    answer = []
    cur = 0
    for i in range(k):
        if i > 0 and i % c == 0:
            answer.append(cur + 1)
            cur = 0
        cur = cur * k + i
    answer.append(cur + 1)
    print ' '.join(map(str, answer))
