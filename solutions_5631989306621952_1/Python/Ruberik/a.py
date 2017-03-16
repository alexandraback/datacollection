from collections import deque

T = int(raw_input())

for i in range(1, T+1):
    print 'Case #%d:' % i,
    word = raw_input()
    result = deque()
    for c in word:
        if c + ''.join(result) < ''.join(result) + c:
            result.append(c)
        else:
            result.appendleft(c)
    print ''.join(result)
        
        
