
def dig(a):
    if not a: return 0
    s = set()
    while a:
        s.add(a%10)
        a//=10
    return s


def f(a):
    if not a: return

    s = set()
    b = a
    while len(s) < 10:
        s |= dig(b)
        if len(s) == 10:
            return b
        b += a 


N = int(input())
for i in range(N):
    a = int(input())
    b = f(a)
    print('Case #{}: {}'.format(i+1, 
        b if b is not None else 'INSOMNIA')
    )

