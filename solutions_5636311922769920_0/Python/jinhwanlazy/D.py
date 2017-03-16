# for small data set
for case in range(int(input())):
    K, C, S = map(int, input().split())
    ans = ' '.join(map(str, range(1, K**C+1, K**(C-1))))
    print('Case #%d:' % (case+1), ans)
