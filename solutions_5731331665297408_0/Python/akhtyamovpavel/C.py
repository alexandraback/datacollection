__author__ = 'Akhtyamov Pavel'

import math

class numbers:
    def __init__(self, fin):
        self.fin = fin
        self.N,self.M = map(int, fin.readline().split())
        self.used = [False]*self.N
        self.curres = 0

        self.g = []*self.N
        for i in range(self.N):
            self.g.append([])
        self.postals = [0]*self.N
        print(self.N)
        self.sumres = 1000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000
        for i in range(self.N):
            self.postals[i] = (int(fin.readline()))
        for i in range(self.M):
            fr, to = map(int, fin.readline().split())
            fr -= 1
            to -= 1
            self.g[fr].append(to)
            self.g[to].append(fr)
            print('ok')
        for i in range(self.N):
            self.ssort(i)
            print('her')
        for i in range(self.N):
            print(self.g[i])
        self.process()

    def ssort(self, curN):
        print(curN)
        print(self.g[curN])
        for i in range(len(self.g[curN])):
            for j in range(1, len(self.g[curN])):

                if(self.postals[self.g[curN][j]] < self.postals[self.g[curN][j-1]]):
                    print(self.postals[self.g[curN][j]], self.postals[self.g[curN][j-1]])
                    print('buk')
                    tmp = self.g[curN][j]
                    self.g[curN][j] = self.g[curN][j-1]
                    self.g[curN][j-1] = tmp
        print(self.g[curN])
        self.step = []
        self.num = []


    def dfs(self,v):
        print(v)
        self.used[v] = True
        self.curres = self.curres*100000 + self.postals[v]

        for i in range(len(self.g[v])):
            to = self.g[v][i]
            if(not self.used[to]):
                self.step.append(to)
                self.num.append(self.postals[to])
        tos = 0
        minc = 100000000
        print(self.used)
        for j in range(len(self.step)):
            if minc > self.num[j] and not self.used[self.step[j]]:
                minc  = self.num[j]
                tos = self.step[j]
        if self.used[tos]:
            return
        print(minc)
        print("dfs", tos)
        self.dfs(tos)




    def process(self):
        for i in range(self.N):
            self.curres = 0
            self.used = [False]*self.N
            self.dfs(i)
            print(self.curres)
            if(self.curres < self.sumres):
                self.sumres = self.curres


if __name__ == '__main__':
    fin = open('test.in','r')
    fout = open('test.out','w')
    T = int(fin.readline())
    for numtest in range(T):
        a = numbers(fin)

        fout.writelines("Case #" + str(numtest + 1) + ": " + str(a.sumres) + "\n")
