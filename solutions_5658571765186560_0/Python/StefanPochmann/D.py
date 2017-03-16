#f = open('D.in')
#def input():
#    return next(f)

T = int(input())
for x in range(1, T + 1):
    X, R, C = map(int, input().split())
    gabriel = X == 1 or \
              X == 2 and R * C % 2 == 0 or \
              X == 3 and R * C % 3 == 0 and R * C > 3 or \
              X == 4 and R * C % 4 == 0 and R * C >= 12
    print('Case #{}: {}'.format(x, 'GABRIEL' if gabriel else 'RICHARD'))
