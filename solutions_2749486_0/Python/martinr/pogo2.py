import heapq


#f = open(r'e:\downloads\A-large.in', 'r')
f = open(r'e:\downloads\B-small-attempt1.in', 'r')
#f = open(r'h:\work\python\code_jam\pogo.txt', 'r')



def solve(X, Y):
    def mydistance(t):
        return max(abs(X-t[0]), abs(Y-t[1]))

    Directions = [(0, 1, 'N'), (0, -1, 'S'), (-1, 0, 'W'), (1, 0, 'E')]
    Visists = {(0,0):1}
    stack = []
    stack.append((0, 0, ""))
    while len(stack) > 0:
        stack = sorted(stack, key=mydistance)
        (x, y, path) = stack[0]
        if x==X and y==Y:
            return path

        stack.pop(0)
        n = len(path)+1
        for d in Directions:
            xx = x+n*d[0]
            yy = y+n*d[1]
            p = path+d[2]
            t = (xx, yy, p)
            if not (xx,yy) in Visists:
                stack.append(t)
                Visists[(xx,yy)] = 1


T = int(f.readline())
for t in range(1, T+1):
    X, Y = map(int, f.readline().split())
    print "Case #%d: %s" % (t, solve(X, Y))


