
def can(x, r, c):
    sm, bi = min(r, c), max(r, c)
    if r * c % x != 0:
        return False
    if sm < (x+1)//2 or bi < x:
        return False
    if x <= 3:
        return True
    elif x == 4:
        if sm == 2:
            return False
        return True
    elif x == 5:
        if sm == 3:
            return bi >= 10
        return True
    elif x == 6:
        if sm == 3:
            return False
        return True
    else:
        return False

def test():
    x, r, c = map(int, input().split(' '))

    return 'GABRIEL' if can(x, r, c) else 'RICHARD'

for case in range(1, int(input())+1):
    print('Case #%d: %s'%(case, test()))
