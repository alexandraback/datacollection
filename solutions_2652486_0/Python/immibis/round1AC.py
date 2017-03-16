class factorlist(object):
    def __init__(self):
        self.dict = {}
        self.size = 0

    def copy(self):
        f = factorlist()
        f.dict = self.dict.copy()
        f.size = self.size
        return f

    def add(self, n, k=1):
        if n in self.dict:
            self.dict[n] += k
        else:
            self.dict[n] = k
        self.size += k
        return self

    def tolist(self):
        L = []
        for x in self.dict:
            for k in range(self.dict[x]):
                L += [x]
        return sorted(L)

    def intersect(self, o):
        rm = []
        for x in self.dict:
            if x not in o.dict:
                rm += [x]
            else:
                self.dict[x] = min(self.dict[x], o.dict[x])
        for x in rm:
            del self.dict[x]
        self.calcsize()
        return self

    def calcsize(self):
        self.size = 0
        for x in self.dict:
            self.size += self.dict[x]

    def union(self, o):
        for x in o.dict:
            if x not in self.dict:
                self.dict[x] = o.dict[x]
            else:
                self.dict[x] = max(self.dict[x], o.dict[x])
        self.calcsize()
        return self

    def __repr__(self):
        return repr(self.tolist())

    def expandComposites(self):
        """if 4 in self.dict:
            self.add(2, self.dict[4] * 2)
        if 9 in self.dict:
            self.add(3, self.dict[9] * 2)
        if 6 in self.dict:
            self.add(2, self.dict[6])
            self.add(3, self.dict[6])
        if 8 in self.dict:
            self.add(2, self.dict[8] * 3)
            self.add(4, self.dict[8])"""
        return self

# returns list of possible factorlists
def factorize(product, M):
    if product == 1: return [factorlist()]
    for x in range(M, 0, -1):
        if (product % x) == 0:
            rv = []
            for pfl in factorize(product / x, M):
                rv += [pfl.copy().add(x)]
                if x == 4:
                    rv += [pfl.copy().add(2).add(2)]
                elif x == 6:
                    rv += [pfl.copy().add(2).add(3)]
                elif x == 9:
                    rv += [pfl.copy().add(3).add(3)]
                elif x == 8:
                    rv += [pfl.copy().add(2).add(2).add(2)]
                    rv += [pfl.copy().add(2).add(4)]
            return rv


def go(N, M, products, expected=None):
    definite = factorlist()
    for x in products:
        factorlists = factorize(x, M)
        numPrimeFactors = 0
        common = factorlists[0]
        for pfl in factorlists:
            if pfl.size > N:
                continue
            #print(x, pfl)
            common = common.intersect(pfl.expandComposites())
        definite = definite.union(common)


    while definite.size < N: definite.add(2)
    return definite.tolist()

if __name__ == '__main__':
    with open("1ACsmall1.txt", "r") as f:
        with open("output.txt", "w") as o:
            f.readline()
            R, N, M, K = f.readline().split(" ")
            R, N, M, K = int(R), int(N), int(M), int(K)
            o.write("Case #1:\n")
            for r in range(R):
                products = [int(x) for x in f.readline().split(" ")]
                o.write(''.join([str(x) for x in go(N, M, products)]) + "\n")









        
