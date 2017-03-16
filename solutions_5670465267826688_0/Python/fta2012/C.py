from itertools import cycle
T = int(raw_input())

def q_multiply(q1, q2):
    w1, x1, y1, z1 = q1
    w2, x2, y2, z2 = q2
    w = w1 * w2 - x1 * x2 - y1 * y2 - z1 * z2
    x = w1 * x2 + x1 * w2 + y1 * z2 - z1 * y2
    y = w1 * y2 + y1 * w2 + z1 * x2 - x1 * z2
    z = w1 * z2 + z1 * w2 + x1 * y2 - y1 * x2
    return w, x, y, z

stringToQuaternion = {
    'i': (0, 1, 0, 0),
    'j': (0, 0, 1, 0),
    'k': (0, 0, 0, 1),
}
for t in xrange(T):
    L, X = (int(c) for c in raw_input().split(' '))
    line = raw_input()
    quaternions = [stringToQuaternion[c] for c in line]
    X = min(X, 4 + (X % 4))
    quaternions *= X
    total = (1, 0, 0, 0)
    for q in quaternions:
        total = q_multiply(total, q)
    ans = 'NO'
    if total == (-1, 0, 0, 0):
        total = (1, 0, 0, 0)
        target = (0, 1, 0, 0)
        for q in quaternions:
            total = q_multiply(total, q)
            if total == target:
                if target == (0, 0, 1, 0):
                    ans = 'YES'
                    break
                total = (1, 0, 0, 0)
                target = (0, 0, 1, 0)

        

    print 'Case #' + str(t + 1) + ': ' + ans
        
