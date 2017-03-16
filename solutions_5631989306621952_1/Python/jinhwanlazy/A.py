from collections import deque
for case in range(int(input())):
    S = input().strip()
    ans = deque()
    for i, c in enumerate(S):
        if all(c >= c_ for c_ in ans):
            ans.appendleft(c)
        else:
            ans.append(c)

    print('Case #%d:' % (case+1), ''.join(ans))
