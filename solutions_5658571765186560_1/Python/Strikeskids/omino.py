
def can(x, r, c):
    sm, bi = min(r, c), max(r, c)
    if r * c % x != 0:
        return False
    if sm < (x+1)//2 or bi < x:
        return False
    if x <= 3:
        return True
    elif x == 4:
        if sm >= 3:
            return True
        assert sm == 2
        return False # Use T shaped tetramino
    elif x == 5:
        if sm >= 4:
            return True # Can always fit around
        assert sm == 3
        return bi >= 10 # Need double size to fit W
    elif x == 6:
        if sm >= 4:
            assert bi >= 6
            '''
                No width 4 length 4
                Thus width 3, and space on one side
                Length 4 has space on top and bottom
                Can connect entire area all around
            '''
            return True
        assert sm == 3
        return False # Use dagger shaped hexamino
    else:
        # Fails because closed loop (smallest size 7)
        assert sm >= 3
        assert x >= 7
        return False

def test():
    x, r, c = map(int, input().split(' '))

    return 'GABRIEL' if can(x, r, c) else 'RICHARD'

for case in range(1, int(input())+1):
    print('Case #%d: %s'%(case, test()))
