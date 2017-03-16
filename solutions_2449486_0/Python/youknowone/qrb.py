
class Cell(object):
    def __init__(self, x, y, v):
        self.x = x
        self.y = y
        self.v = v
        self.field = None
        self.left = {}
        self.right = {}
        self.up = {}
        self.down = {}

    def __repr__(self):
        return '%03d %5s' % (self.v, self.ok())

    @property
    def cell_left(self):
        return self.field[self.x-1, self.y]
    @property
    def cell_right(self):
        return self.field[self.x+1, self.y]
    @property
    def cell_up(self):
        return self.field[self.x, self.y-1]
    @property
    def cell_down(self):
        return self.field[self.x, self.y+1]
    
    def accept_left(self, h):
        if not h in self.left:
            self.left[h] = self.v <= h and self.cell_left.accept_left(h)
        return self.left[h]
    def accept_right(self, h):
        if not h in self.right:
            self.right[h] = self.v <= h and self.cell_right.accept_right(h)
        return self.right[h]
    def accept_up(self, h):
        if not h in self.up:
            self.up[h] = self.v <= h and self.cell_up.accept_up(h)
        return self.up[h]
    def accept_down(self, h):
        if not h in self.down:
            self.down[h] = self.v <= h and self.cell_down.accept_down(h)
        return self.down[h]

    def ok(self):
        return self.accept_left(self.v) and self.accept_right(self.v) \
            or self.accept_up(self.v) and self.accept_down(self.v)

class EdgeCell(Cell):
    def accept_left(self, h):
        return True
    def accept_right(self, h):
        return True
    def accept_up(self, h):
        return True
    def accept_down(self, h):
        return True

    def ok(self):
        return '-----'

class Field(object):
    def __init__(self, height, width, lines):
        self.cells = []
        self.height = height
        self.width = width
        
        for xx in xrange(0, height):
            line = lines[xx]
            heights = map(int, line.split(' '))
            for i, h in enumerate(heights):
                cell = Cell(i, xx, h)
                self.put(cell)
            assert len(heights) == width

    def put(self, *cs):
        for c in cs:
            c.field = self
            assert len(self.cells) == self.width * c.y + c.x
        self.cells += cs

    def __getitem__(self, vec):
        x, y = vec
        cc = None
        if x < 0:
            cc = self[0, y]
        elif y < 0:
            cc = self[x, 0]
        elif x >= self.width:
            cc = self[self.width - 1, y]
        elif y >= self.height:
            cc = self[x, self.height - 1]
        if cc is not None:
            return EdgeCell(x, y, cc.v)
        return self.cells[y * self.width + x]

    def ok(self):
        for c in self.cells:
            if not c.ok():
                return False
        return True

    def __repr__(self):
        buflist = ['%d x %d' % (self.width, self.height)]
        eedge = self[-1, -1]
        buflist.append(str([eedge] + [self[x, -1] for x in xrange(0, self.width)] + [eedge]))
        for x in xrange(0, self.height):
            l = [self[-1, x]] + self.cells[x * self.width:(x + 1) * self.width] + [self[self.width, x]]
            buflist.append(str(l))
        buflist.append(str([eedge] + [self[x, self.height] for x in xrange(0, self.width)] + [eedge]))
        return '\n'.join(buflist)

if __name__ == '__main__':
    count = input()
    for x in range(0, count):
        line = raw_input()
        height, width = map(int, line.split(' '))
        lines = list(raw_input() for xx in xrange(0, height))

        field = Field(height, width, lines)

        print 'Case #%d:' % (x + 1), 'YES' if field.ok() else 'NO'
        #print field