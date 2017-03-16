#f = open('D.in')
#def input():
#    return next(f)

T = int(input())
for x in range(1, T + 1):
    X, R, C = map(int, input().split())
    A = R * C
    s, S = sorted((R, C))
    gabriel = A % X == 0 and \
              (X == 1 or
               X == 2 or
               X == 3 and s >= 2 or
               X == 4 and s >= 3 or
               X == 5 and s >= 3 and A > 15 or
               X == 6 and s >= 4)
    print('Case #{}: {}'.format(x, 'GABRIEL' if gabriel else 'RICHARD'))
