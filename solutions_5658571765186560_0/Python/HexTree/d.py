list = [[2, 1, 2], [2, 2, 2], [2, 1, 4], [2, 2, 3], [3, 2, 3], [2, 2, 4], [3, 3, 3], [2, 3, 4], [3, 3, 4], [4, 3, 4], [2, 4, 4], [4, 4, 4]]

g = open("data1.txt", 'w')
with open("data.txt", 'r') as f:
    T = int(f.readline())
    for r in range(T):
        X, R, C = [int(x) for x in f.readline().split()]
        if X == 1 or [X, R, C] in list or [X, C, R] in list:
            g.write("Case #%d: GABRIEL\n" % (r+1))
        else:
            g.write("Case #%d: RICHARD\n" % (r+1))
f.close()
g.close()