from sys import stdin

T = int(stdin.readline())
t = 0

while t < T:
    t += 1
    route = []
    X, Y = map(int, stdin.readline().split())
    jump = 0
    if abs(Y) > abs(X):
        L, S = Y, X
        l = 'S'
        r = 'N'
        u = 'E'
        d = 'W'
    else:
        L, S = X, Y
        l = 'W'
        r = 'E'
        u = 'N'
        d = 'S'

    direction, c = (r,1) if L > 0 else (l, -1)
    LC = 0
    while jump+1 < abs(S):
        jump += 1
        LC += c*jump
        route.append(direction)
    jump += 1

    if S < 0:
        route.append(d)
        jump += 1
    elif S > 0:
        route.append(u)
        jump += 1

    while abs(LC+c*jump) < abs(L):
        LC += c*jump
        route.append(direction)
        jump += 1

    route.extend((abs(L)-abs(LC))*[l,r])
        
    print "Case #%d: %s" % (t, ''.join(route))
