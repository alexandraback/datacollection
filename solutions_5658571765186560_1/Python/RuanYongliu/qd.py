import copy

class OminoUtil(object):
    @staticmethod
    def simply(graph):
        new_graph = copy.deepcopy(graph)
        for time in xrange(2):
            empty_first_col = True
            for line in new_graph:
                if line[0]:
                    empty_first_col = False
            if empty_first_col:
                for line in new_graph:
                    line.reverse()
                    line.pop()
                    line.reverse()
            else:
                for line in new_graph:
                    line.pop()
        return new_graph

    @staticmethod
    def hash(graph):
        b = 1
        h = 0
        for line in graph:
            for item in line:
                if item:
                    h += b
                b *= 2
        return h

    @staticmethod
    def mirror(graph):
        result = []
        for line in graph:
            new_line = copy.deepcopy(line)
            new_line.reverse()
            result.append(new_line)
        return OminoUtil.move(result)

    @staticmethod
    def rotate(graph):
        result = copy.deepcopy(graph)
        n = len(graph)
        for x in xrange(n):
            for y in xrange(n):
                result[n - 1 - y][x] = graph[x][y]
        return OminoUtil.move(result)

    @staticmethod
    def move(graph):
        result = copy.deepcopy(graph)
        while True not in result[0]:
            result = result[1:] + [result[0]]
        while True:
            true_in_first_col = False
            for line in result:
                if line[0]:
                    true_in_first_col = True
                    break
            if true_in_first_col:
                break
            else:
                for line in result:
                    line.reverse()
                    line.pop()
                    line.reverse()
                    line.append(False)
        return result

    @staticmethod
    def tuple(graph):
        result = []
        for x in xrange(len(graph)):
            for y in xrange(len(graph[x])):
                if graph[x][y]:
                    result.append((x, y))
        return result

class Omino(object):
    def __init__(self, n):
        self.n = n
        self.graphs = {}
        self.graph_dict = {}
        self.__gen_graph__()

    def __gen_graph__(self):
        tmp_graph = []
        for i in xrange(self.n):
            tmp_graph.append([False] * (self.n + 2))
        self.__travers__(0, 2, tmp_graph, self.n)

    def __travers__(self, x, y, cur, remain):
        if remain == 0:
            new_graph = OminoUtil.simply(cur)
            graphs = []
            hash_set = set()
            for tm in xrange(2):
                for t in xrange(4):
                    h = OminoUtil.hash(new_graph)
                    if h not in hash_set:
                        graphs.append(new_graph)
                        hash_set.add(h)
                    new_graph = OminoUtil.rotate(new_graph)
                new_graph = OminoUtil.mirror(new_graph)
            h = min(hash_set)
            if not self.graphs.has_key(h):
                self.graphs[h] = map(OminoUtil.tuple, graphs)
            return
        if x == self.n:
            return
        if y >= 2:
            if x == self.n - 1 and y == self.n + 1:
                nx = 0
                ny = 1
            elif y == self.n + 1:
                nx = self.n - 1
                ny = x + 3
            elif x == 0:
                nx = y - 1
                ny = 2
            else:
                nx = x - 1
                ny = y + 1
        else:
            if x == self.n - 1 and y == 0:
                nx = self.n
                ny = 0
            elif y == 1:
                nx = x
                ny = 0
            else:
                nx = x + 1
                ny = 1
        if x == 0 and y == 2:
            cur[x][y] = True
            self.__travers__(nx, ny, cur, remain - 1)
            cur[x][y] = False
            return
        if (x > 0 and cur[x - 1][y]) or (y > 0 and cur[x][y - 1]) or (y < self.n + 1 and cur[x][y + 1]):
            cur[x][y] = True
            self.__travers__(nx, ny, cur, remain - 1)
            cur[x][y] = False
        self.__travers__(nx, ny, cur, remain)


#    def print_graph(self):
#        for graph in self.graphs:
#            for line in graph:
#                for item in line:
#                    print "*" if item else ".",
#                print
#            print "-------------------------------------"
#            print
#        print "%s Total." % len(self.graphs)

    def get_graph(self):
        return self.graphs

def traverse(x, y, r, c, cur, count, used, graphs, targeth):
    if len(used) == len(graphs) or targeth in used:
        return
    if x == r:
        used.update(filter(lambda k: count[k] > 0, count.keys()))
        return
    if cur[x][y]:
        if y + 1 == c:
            traverse(x + 1, 0, r, c, cur, count, used, graphs, targeth)
        else:
            traverse(x, y + 1, r, c, cur, count, used, graphs, targeth)
    for h, ones in graphs.items():
        for graph in ones:
            if graph[0] == (0, 0)  and cur[x][y] or graph[0] != (0, 0) and  not cur[x][y]:
                continue
            adapt = True
            for ax, ay in graph:
                if x + ax >= r or y + ay >= c or cur[x + ax][y + ay]:
                    adapt = False
                    break
            if adapt:
                for ax, ay in graph:
                    cur[x + ax][y + ay] = True
                count[h] = count.get(h, 0) + 1
                if y + 1 == c:
                    traverse(x + 1, 0, r, c, cur, count, used, graphs, targeth)
                else:
                    traverse(x, y + 1, r, c, cur, count, used, graphs, targeth)
                for ax, ay in graph:
                    cur[x + ax][y + ay] = False
                count[h] = count[h] - 1


def cover(graphs, r, c, n):
    if r > c:
        r, c = c, r
    if r * c % n != 0:
        return "RICHARD"
    if n > c:
        return "RICHARD"
    if r < (n + 1) / 2 or c < (n + 2) / 2:
        return "RICHARD"
    used = set()
    for h, ones in graphs.items():
        if h in used:
            continue
        for graph in ones:
            if h in used:
                break
            for x in xrange(r):
                if h in used:
                    break
                for y in xrange(c):
                    if h in used:
                        break
                    adapt = True
                    for ax, ay in graph:
                        if x + ax >= r or y + ay >= c:
                            adapt = False
                            break
                    if adapt:
                        cov = []
                        for i in xrange(r):
                            cov.append([False] * c)
                        for ax, ay in graph:
                            cov[x + ax][y + ay] = True
                        count = {h: 1}
                        traverse(0, 0, r, c, cov, count, used, graphs, h)
        if not h in used:
            print h
            return "RICHARD"
    return "GABRIEL"

def simple_compute(x, r, c):
    if r * c % x > 0:
        return "RICHARD"
    if r > c:
        r, c = c, r
    if x > c:
        return "RICHARD"
    if r < (x + 1) / 2:
        return "RICHARD"
    if r < x:
        if x == 4 and r == 2:
            return "RICHARD"
        elif x == 5:
            return "GABRIEL"
        elif x == 6:
            if r == 3:
                return "RICHARD"
            else:
                return "GABRIEL"
        return ""
    return "GABRIEL"

def main():
    casenum = input()
    x_omino_dict = {}
    for caseidx in xrange(1, casenum + 1):
        x, r, c = map(int, raw_input().split())
        if x >= 7:
            ans = "RICHARD"
        else:
            ans = simple_compute(x, r, c)
            if ans == "":
                if not x_omino_dict.has_key(x):
                    x_omino_dict[x] = Omino(x)
                omino = x_omino_dict[x]
                ans = cover(omino.get_graph(), r, c, x)
        print "Case #%d: %s" % (caseidx, ans)

if __name__ == "__main__":
    main()
