import sys

def factors(n):
    fs = []
    while n%2 == 0:
        fs.append(2)

def solve(b,m):
    #if m > 2**(b-2):
    #    return 'IMPOSSIBLE'
    bs = ['0'*b, '0'*(b-1)+'1']
    m -= 1
    for i in range(2,b):
        bi = b-i-1
        x = 'x'*(i-1)
        nl = min(2**(i-2),m)
        m -= nl
        if nl == 2**(i-2):
            x = '1'*(i-1)
        elif nl == 0:
            x = '0'*(i-1)
        else:
            x = format(nl, '0' + str(i-2) + 'b') + '0'
        ans = '0'*(bi+1)+'1'+x
        #print(i, nl, m, ans)
        bs.append(ans)
    if m != 0:
        return 'IMPOSSIBLE'
    return 'POSSIBLE\n'+'\n'.join(reversed(bs))




if __name__ == '__main__':
    lines = (x.strip() for x in sys.stdin.readlines()[1:])
    for t, l in enumerate(lines):
        print('Case #{}: {}'.format(t+1, solve(*[int(x) for x in l.split()])))

