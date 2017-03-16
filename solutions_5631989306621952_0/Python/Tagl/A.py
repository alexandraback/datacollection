from collections import deque
n = int(input())
for i in range(n):
    s = input()
    r = deque([s[0]])
    for j in range(1,len(s)):
        if s[j] < r[0]:
            r.append(s[j])
        else:
            r.appendleft(s[j])
    print('Case #%d: %s' %((i+1),''.join(r)))
