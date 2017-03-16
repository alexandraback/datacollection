from collections import Counter
from itertools import groupby
mod = 1000000007

class UnionFind:
    def __init__(self, n):
        self.parent = [-1] * n
        self.rank = [0] * n

    def find(self, x):
        if self.parent[x] < 0:
            return x
        else:
            self.parent[x] = self.find(self.parent[x])
            return self.parent[x]

    def union(self, x, y):
        x, y = self.find(x), self.find(y)
        if x == y:
            return
        if self.rank[x] < self.rank[y]:
            self.parent[x] = y
        else:
            self.parent[y] = x
            if self.rank[x] == self.rank[y]:
                self.rank[x] += 1

    def same(self, x, y):
        return self.find(x) == self.find(y)

    def count_group(self):
        length = len(self.parent)
        cnt = 0
        for i in xrange(length):
            if self.parent[i] == -1:
                cnt += 1
        return cnt


def factorial(n):
    if n == 1:
        return 1
    return (n * factorial(n - 1)) % mod

if __name__ == '__main__':
    T = input()
    for t in xrange(1, T + 1):
        N = input()
        trains = raw_input().split()
        pre, center, post = set(), set(), set()
        for i in xrange(len(trains)):
            tmp = []
            for k, g in groupby(trains[i]):
                tmp.append(k)
            trains[i] = ''.join(tmp)
        for train in trains:
            pre.add(train[0])
            post.add(train[-1])
            for car in train[1:-1]:
                center.add(car)
        # print trains, pre, post
        impossible = False
        if pre & center or post & center:
            impossible = True

        connect = dict()
        same_train = Counter()
        for train in trains:
            if len(train) == 1:
                same_train[train] += 1
            else:
                if ord(train[0]) - ord('a') in connect:
                    impossible = True
                else:
                    connect[ord(train[0]) - ord('a')] = ord(train[-1]) - ord('a')
        tree = UnionFind(26)
        occu_cnt = set()
        for k, v in connect.items():
            tree.union(k, v)
            occu_cnt.add(k)
            occu_cnt.add(v)
        for k, v in same_train.items():
            occu_cnt.add(ord(k) - ord('a'))
        rest = 26 - len(occu_cnt)
        pattern = tree.count_group() - rest

        # print tree.count_group(), pattern
        for k in connect:
            visited = set()
            cur = k
            while 1:
                if cur in visited:
                    impossible = True
                    break
                visited.add(cur)
                if cur in connect:
                    cur = connect[cur]
                else:
                    break

        # print trains
        if impossible:
            print "Case #%d: 0" % t
        else:
            ret = 1
            for k, v in same_train.items():
                ret *= factorial(v) % mod
            # print ret, pattern
            ret *= factorial(pattern)
            print "Case #%d: %d" % (t, ret % mod)