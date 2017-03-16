import copy


class Board(object):
    r = None
    c = None
    m = None

    def __init__(self, r, c, m, f):
        self.r = r
        self.c = c
        self.m = m
        self.f = f
        self.actual_m = self.r * self.c
        self.start_clicked = []
        self.clicked = []
        self.data = [['*' for j in range(self.c)] for i in range(self.r)]

    def test_0(self, x, y):
        if y < self.r - 1:
            if self.data[y + 1][x] == '*':
                return False
        if y > 0:
            if self.data[y - 1][x] == '*':
                return False
        if x < self.c - 1 and y < self.r - 1:
            if self.data[y + 1][x + 1] == '*':
                return False
        if y > 0 and x < self.c - 1:
            if self.data[y - 1][x + 1] == '*':
                return False
        if x > 0 and y < self.r - 1:
            if self.data[y + 1][x - 1] == '*':
                return False
        if y > 0 and x > 0:
            if self.data[y - 1][x - 1] == '*':
                return False
        if x > 0:
            if self.data[y][x - 1] == '*':
                return False
        if x < self.c - 1:
            if self.data[y][x + 1] == '*':
                return False
        return True

    def test_canbeopen(self, x, y):
        test_0 = self.test_0
        if y < self.r - 1:
            if test_0(x, y + 1):
                return True
        if y > 0:
            if test_0(x, y - 1):
                return True
        if x < self.c - 1 and y < self.r - 1:
            if test_0(x + 1, y + 1):
                return True
        if y > 0 and x < self.c - 1:
            if test_0(x + 1, y - 1):
                return True
        if x > 0 and y < self.r - 1:
            if test_0(x - 1, y + 1):
                return True
        if y > 0 and x > 0:
            if test_0(x - 1, y - 1):
                return True
        if x > 0:
            if test_0(x - 1, y):
                return True
        if x < self.c - 1:
            if test_0(x + 1, y):
                return True
        return False

    def test(self):
        r, c, m = self.r, self.c, self.m
        m_c = 0
        for y, i in enumerate(self.data):
            for x, j in enumerate(i):
                if j == '*':
                    m_c += 1
                if j == 'c' and not r * c - m == 1:
                    if not self.test_0(x, y):
                        print 'error', r, c, m
                if j == '.':
                    if not self.test_canbeopen(x, y):
                        print 'error', r, c, m

        if not m_c == self.m:
            print 'error!', r, c, m

    def draw(self):
        for i in self.data:
            for j in i:
                self.f.write('%s' % j)
            self.f.write('\n')
        # self.test()

    def click(self, x, y):
        if self.data[y][x] == '*':
            self.data[y][x] = 'c'
            self.actual_m -= 1
        if self.actual_m == self.m:
            self.draw()
            return True
        if y < self.r - 1:
            if self.data[y + 1][x] == '*':
                self.data[y + 1][x] = '.'
                self.actual_m -= 1
        if y > 0:
            if self.data[y - 1][x] == '*':
                self.data[y - 1][x] = '.'
                self.actual_m -= 1
        if x < self.c - 1 and y < self.r - 1:
            if self.data[y + 1][x + 1] == '*':
                self.data[y + 1][x + 1] = '.'
                self.actual_m -= 1
        if y > 0 and x < self.c - 1:
            if self.data[y - 1][x + 1] == '*':
                self.data[y - 1][x + 1] = '.'
                self.actual_m -= 1
        if x > 0 and y < self.r - 1:
            if self.data[y + 1][x - 1] == '*':
                self.data[y + 1][x - 1] = '.'
                self.actual_m -= 1
        if y > 0 and x > 0:
            if self.data[y - 1][x - 1] == '*':
                self.data[y - 1][x - 1] = '.'
                self.actual_m -= 1
        if x > 0:
            if self.data[y][x - 1] == '*':
                self.data[y][x - 1] = '.'
                self.actual_m -= 1
        if x < self.c - 1:
            if self.data[y][x + 1] == '*':
                self.data[y][x + 1] = '.'
                self.actual_m -= 1
        if self.actual_m == self.m:
            self.draw()
            return True
        else:
            _data = copy.deepcopy(self.data)
            for k, i in enumerate(self.data):
                for v, j in enumerate(i):
                    if j == '.' and (v, k) not in self.clicked:
                        self.clicked.append((v, k))
                        if self.click(v, k):
                            return True
                        # self.clicked.remove((v, k))
                        self.data = copy.deepcopy(_data)

    def result(self):
        for y in range(self.r):
            for x in range(self.c):
                if (x, y) not in self.start_clicked:
                    self.start_clicked.append((x, y))
                    self.clicked = []
                    clickResult = self.click(x, y)
                    if clickResult:
                        return True
                    else:
                        self.data = [['*' for j in range(self.c)]
                                     for i in range(self.r)]
                        self.actual_m = self.r * self.c
                        continue
        self.f.write('Impossible\n')


def main():
    # with open('c.out', 'wb') as f:
    #     b = Board(3, 2, 5, f)
    #     b.result()
    with open('c.in', 'r') as c:
        with open('c.out', 'wb') as f:
            for i, l in enumerate(c):
                if i == 0:
                    print i
                else:
                    r, c, m = [int(j) for j in l.strip().split(' ')]
                    f.write("Case #%d:\n" % i)
                    b = Board(r, c, m, f)
                    b.result()

if __name__ == '__main__':
    main()
