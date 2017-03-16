import sys
sys.stdin = open('A-large.in')
sys.stdout = open('out.txt', 'w')

t = int(input())
for case in range(t):
    smax, s = input().split()
    smax = int(smax)
    s = list(map(int, list(s)))
    res = 0
    standing = 0
    for i in range(smax+1):
        if s[i] > 0:
            if standing < i:
                need = i - standing
                standing += need
                res += need
            standing += s[i]
    print('Case #{}: {}'.format(case+1, res))


