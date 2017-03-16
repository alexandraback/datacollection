inf = open('input.txt', 'r')
ouf = open('output.txt', 'w')


def next1(cur, v):
    if cur[0] == '1':
        return (v, cur[1])
    if cur[0] == v:
        return ('1', (cur[1] + 1) % 2)
    if cur[0] == 'i' and v == 'j':
        return ('k', cur[1])
    if cur[0] == 'j' and v == 'i':
        return ('k', (cur[1] + 1) % 2)
    if cur[0] == 'i' and v == 'k':
        return ('j', (cur[1] + 1) % 2)
    if cur[0] == 'k' and v == 'i':
        return ('j', cur[1])
    if cur[0] == 'j' and v == 'k':
        return ('i', cur[1])
    if cur[0] == 'k' and v == 'j':
        return ('i', (cur[1] + 1) % 2)
    
    
        
    
t = int(inf.readline())
c = 0
for j in range(t):
    L, X = map(int, inf.readline().split())
    s1 = str(inf.readline().rstrip())
    cur = (s1[0], 1)
    s = ''
    for i in range(X):
            s += s1    
    for i in range(1, len(s)):
        cur = next1(cur, s[i])
        
    if cur != ('1', 0):
        print('Case #', end = '', file = ouf)
        print(j + 1, end = '', file = ouf)
        print(':', end = ' ', file = ouf)
        print('NO', file = ouf)  
        continue
    cur = (s[0], 1)
    ans = -1
    if cur[0] == 'i' and cur[1] == 1:
        ans = 0
        
    ans1 = -1
    flag = False
    for i in range(1, L*X):
        cur = next1(cur, s[i])
        if cur[0] == 'i' and cur[1] == 1 and ans == -1:
            ans = i
        if cur[0] == 'k' and cur[1] == 1:
            ans1 = i
    if ans1 > ans and ans != -1 and ans1 != -1:
        print('Case #', end = '', file = ouf)
        print(j + 1, end = '', file = ouf)
        print(':', end = ' ', file = ouf)
        print('YES', file = ouf)    
    else:
        print('Case #', end = '', file = ouf)
        print(j + 1, end = '', file = ouf)
        print(':', end = ' ', file = ouf)
        print('NO', file = ouf)        
        
        
inf.close()
ouf.close()


