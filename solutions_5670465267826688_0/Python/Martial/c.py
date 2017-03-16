import sys
sys.stdin = open('C-small-attempt0.in')
sys.stdout = open('out.txt', 'w')

v = {'1': [1,0,0,0],
     'i': [0,1,0,0],
     'j': [0,0,1,0],
     'k': [0,0,0,1]
     }

def mul(x, y):
    a,b,c,d = x
    e,f,g,h = y
    l = a * e - b * f - c * g - d * h
    m = a * f + b * e + c * h - d * g
    n = a * g + c * e - b * h + d * f
    o = a * h + d * e + b * g - c * f
    return [l,m,n,o]

t = int(input())
for case in range(t):
    print(case, end=' ', file=sys.stderr)
    l, x = list(map(int, input().split()))
    if x > 8:
        x = 8 + x % 4
    s = input() * x
    n = l * x

    i = 0
    ok = 0

    prod = v['1']
    while ok == 0 and i < n:
        prod = mul(prod, v[s[i]])
        i += 1
        if prod == v['i']:
            ok += 1

    prod = v['1']
    while ok == 1 and i < n:
        prod = mul(prod, v[s[i]])
        i += 1
        if prod == v['j']:
            ok += 1

    prod = v['1']
    while i < n:
        prod = mul(prod, v[s[i]])
        i += 1

    if ok == 2 and prod == v['k']:
        res = 'YES'
    else:
        res = 'NO'
    print('Case #{}: {}'.format(case+1, res))


