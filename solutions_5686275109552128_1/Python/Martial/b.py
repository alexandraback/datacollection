import sys
sys.stdin = open('B-large.in')
sys.stdout = open('out.txt', 'w')

n_cases = int(input())
for case in range(n_cases):
    print(case, end=' ', file=sys.stderr)
    d = int(input())
    p = list(map(int, list(input().split())))
    res = 10000
    for t in range(1, 1005):
        splits = 0
        for i in range(d):
            n = p[i] // t
            if p[i] % t > 0:
                n += 1
            splits += n - 1
        if splits + t < res:
            res = splits + t
        if t+1 >= res :
            break
    print('Case #{}: {}'.format(case+1, res))


