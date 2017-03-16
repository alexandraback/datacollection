__author__ = 'j0hnny'


def find_board(rows, cols, mines):

    def check(s):
        def unlock_all(x, y):
            q = {(x, y)}
            open = get_open(q, x, y)
            if open.issubset(s):
                while len(open) != 0:
                    q = q | open
                    open = set()
                    for ix, iy in q:
                        o = get_open(q, ix, iy)
                        if o.issubset(s):
                            open = open | o
            return s.issubset(q)

        for u, v in s:
            if unlock_all(u, v):
                return u, v

    def get_open(prev, x, y):
        dx = [x]
        if x > 0:
            dx.append(x-1)
        if x < rows-1:
            dx.append(x+1)
        dy = [y]
        if y > 0:
            dy.append(y-1)
        if y < cols-1:
            dy.append(y+1)
        res = set()
        for ix in dx:
            for iy in dy:
                #print "%d - %d %s" % (ix, iy, prev)
                if (ix != x or iy != y) and not (ix, iy) in prev:
                    #print "%d - %d" % (ix, iy)
                    res = res | {(ix, iy)}
        #print "get open %s" % res
        return res

    def dijkstra(q, new):
        #print "dijkstra %s" % q
        if len(q) == rows*cols - mines:
            c = check(q)
            if not c is None:
                cx, cy = c
                return q, cx, cy
            else:
                return None
        o = set()
        #for (u, v) in q:
        u, v = new
        o = o | get_open(q, u, v)
        for p in o:
            v = dijkstra(q | {p}, p)
            if not v is None:
                return v

    for r in range(rows):
        for c in range(cols):
            board = dijkstra({(r, c)}, (r, c))
            if not board is None:
                return board


def draw_board(out, s, r, c, cx, cy):
    for x in range(r):
        for y in range(c):
            if x == cx and y == cy:
                out.write('c')
            elif (x, y) in s:
                out.write('.')
            else:
                out.write('*')
        out.write('\n')


if __name__ == '__main__':
    with open('C-small-attempt1.in', 'r') as input:
        with open('output', 'w') as output:
            cases = int(input.readline())
            for c in range(cases):
                row, col, m = [int(x) for x in input.readline().split()]
                f = find_board(row, col, m)

                str = 'Case #%d:\n' % (c+1)
                if f is None:
                    str += 'Impossible\n'
                    output.write(str)
                else:
                    output.write(str)
                    board, cx, cy = f
                    str += '%d, %d\n' % (cx, cy)
                    str += '%s' % board
                    draw_board(output, board, row, col, cx, cy)
                print str