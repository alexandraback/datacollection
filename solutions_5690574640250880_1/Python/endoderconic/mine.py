import sys

pattern = "Case #{0}: {1}"


class BloquedException(Exception):
    def __init__(self, message):
        self.message = message
    def __str__(self):
        return self.message
class EchecException(Exception):
    def __init__(self,message="Impossible"):
        self.message = message
    def __str__(self):
        return self.message
    
class Point:
    
    def __init__(self, x, y):
        self._n = 0
        self._marqued = []
        self._mine = False
        self._x = x
        self._y = y
        self._neighboors = []
        self._start = False

    def init_neighboors(self,neighboors):
        if not self._neighboors:
            self._neighboors = neighboors
            self._n = len(neighboors)

    def update(self,check=0):
        for p in self._neighboors:
            if self._mine and self not in p._marqued:
                p._marqued.append(self)
            elif self in p._marqued:
                p._marqued.remove(self)
        if check:
            for p in self._neighboors:
                if p.is_bloqued():
                    raise BloquedException("bloquer")

    
    def is_bloqued(self):
        return not self._mine and self._marqued and len([i for i in self._neighboors if (i._mine or i._marqued)]) == self._n

    def __add__(self,p):
        return Point(self._x+p._x,self._y+p._y)

    def is_valid(self):
        return self._x >= 0 and self._y >= 0
    
    def __str__(self):
        if self._mine:
            return "*"
        elif self._start:
            return "c"
        #elif self._marqued:
        #   return "x"
        else:
            return "."


class Map:
    def __init__(self,row,col,mine):
        self._row = row
        self._col = col
        self._r_l = row
        self._c_l = col
        self._mine = mine
        self.points = []

        for y in xrange(row):
            for x in xrange(col):
                self.points.append(Point(x,y))
        for p in self.points:
            p.init_neighboors(self.get_neighboors(p._x,p._y))
    
    def convert_index(self, index):
        return index % self._col, index / self._col
    
    def convert_coord(self, x, y):
        return y*self._col + x

    def get_neighboors(self,x,y):
        n = []
        if x > 0:
            n.append(self.points[self.convert_coord(x-1,y)])
            if y > 0:
                n.append(self.points[self.convert_coord(x-1,y-1)])
            if  y < self._row -1:
                n.append(self.points[self.convert_coord(x-1,y+1)])
        if x < self._col - 1:
            n.append(self.points[self.convert_coord(x+1,y)])
            if y > 0:
                n.append(self.points[self.convert_coord(x+1,y-1)])
            if  y < self._row -1:
                n.append(self.points[self.convert_coord(x+1,y+1)])
        if y > 0:
            n.append(self.points[self.convert_coord(x,y-1)])
        if  y < self._row - 1:
            n.append(self.points[self.convert_coord(x,y+1)])
        return n

    def neigh_number(self,x,y):
        return len(self.get_neighboors(x,y))

    def fill_perimeter(self):
        index = 0
        n = 0
        while self._mine > 2*((self._col-2*n)+(self._row-2-2*n)) and 2*((self._col-2*n)+(self._row-2-2*n)) > 0:
            for x in xrange(n,self._col-n):
                p = self.points[self.convert_coord(x,n)]
                p._mine = True
                p.update()
                p = self.points[self.convert_coord(x,self._row-1-n)]
                p._mine = True
                p.update()
            for y in xrange(n+1,self._row-1-n):
                p = self.points[self.convert_coord(n,y)]
                p._mine = True
                p.update()
                p = self.points[self.convert_coord(self._col-1-n,y)]
                p._mine = True
                p.update()
            self._mine -= 2*((self._col-2*n)+(self._row-2-2*n))
            n+=1
        if 2*((self._col-2*n)+(self._row-2-2*n)) <= 0:
            raise EchecException()

    def set_start(self, onlyOne=0):
        for p in self.points:
            if not p._marqued and not p._mine:
                p._start = True
                return 
            elif p._marqued and onlyOne and not p._mine:
                p._start = True
                return
        raise EchecException()
    
    def fill_row(self, nrow):
        """ nrow from 0 """
        index = nrow * self._col
        for i in xrange(self._col - self._c_l, self._col):
            p = self.points[index + i]
            p._mine = True

    def fill_col(self, ncol):
        """ ncol from 0 """
        index = ncol
        for i in xrange(self._row - self._r_l, self._row):
            p = self.points[index + i * self._col]
            p._mine = True

    def update(self,nrow,ncol):
        y = nrow
        if y >= 0:
            for x in xrange(max(ncol,0),self._col):
                p =  self.points[y * self._col + x]
                p.update()
        x = ncol
        if x >= 0:
            for y in xrange(max(nrow,0), self._row):
                p =  self.points[y * self._col + x]
                p.update()

    def fill_mines(self):
        m = min(self._r_l,self._c_l)
        while self._mine >= m:
            self._mine -= m
            if self._r_l == m:
                self.fill_col(self._col - self._c_l)
                self._c_l -=1
                if not self._c_l:
                    raise EchecException("full col")
            else:
                self.fill_row(self._row - self._r_l)
                self._r_l -= 1
                if not self._r_l:
                    raise EchecException("full row")
            m = min(self._r_l,self._c_l)
        self.update(self._row - self._r_l - 1, 
                    self._col - self._c_l -1)


    def set_mines(self,check):
        index = 0
        if self._mine:
            for i in xrange(self._mine-1):
                while True:
                    point = self.points[index]
                    if not point._mine:
                        point._mine = True
                        point.update()
                        break
                    index+=1
                    if index >= len(self.points):
                        raise EchecException()
            while True:
                point = self.points[index]
                if not point._mine:
                    point._mine = True
                    try:
                        point.update(check)
                        break
                    except BloquedException as e:
                        point._mine = False
                        point.update()
                        index+=1
                        if index >= len(self.points):
                            raise EchecException()
                index+=1
                if index >= len(self.points):
                    raise EchecException()


    def up_neighboors(self, index):
        point = self.points[index]
        point.update()

    def up_point(self,point,neighboor):
        if point._mine and point not in neighboor._marqued:
            neighboor._marqued.append(point)
            if neighboor.is_bloqued():
                raise BloquedException()

        elif point in neighboor._marqued:
            neighboor._marqued.remove(point)
        
    def __str__(self):
        s = []
        for i,p in enumerate(self.points):
            if i and not (i % self._col):
                s.append("\n")  
            s.append(str(p))
        return "".join(s)


def do_map(f):
    r,c,m = map(int,f.readline().rstrip("\n").split())
    if r*c - m in [2,3] and r>1 and c>1:
        return
    _map = Map(r,c,m)
    try:
        if m:
            _map.fill_mines()
            if _map._mine:
                _map.set_mines(m != r*c-1)
        _map.set_start(m == r*c-1)
        return _map
    except EchecException as e:
        return

if __name__=="__main__":
    with open(sys.argv[1]) as f:
        ntests = int(f.readline())
        for i in xrange(1,ntests+1):
            m = do_map(f)
            if not m:
                print pattern.format(i,"\nImpossible")
            else:
                print pattern.format(i,"\n"+str(m))

