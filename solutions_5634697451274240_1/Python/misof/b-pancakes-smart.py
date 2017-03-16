T = int(input())
for tid in range(1,T+1):
    start = input() + '+'
    print('Case #{}: {}'.format(tid,start.count('+-')+start.count('-+')))
