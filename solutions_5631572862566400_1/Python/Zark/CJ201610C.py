from sys import stdin, stdout

class Solver :

    def run(self) :
        caseNum = int(stdin.readline())
        for caseIndex in range(caseNum) :
            self.input()
            self.exe()
            self.output(caseIndex + 1)

    def input(self) :
        self.num = int(stdin.readline())
        self.bff = [int(_) - 1 for _ in stdin.readline().split()]

    def exe(self) :
        self.counterBff = [[] for _ in range(self.num)]
        for i in range(self.num) :
            self.counterBff[self.bff[i]].append(i)

        circleLen = []
        for i in range(self.num) :
            circleLen.append(self.findCircle(i))

        lineLen = []
        for i in range(self.num) :
            if self.bff[self.bff[i]] == i :
                lineLen.append(self.findLine(i))
            else :
                lineLen.append(0)

        self.result = 0
        for i in range(self.num) :
            self.result = max(self.result, circleLen[i])
        alter = 0
        for i in range(self.num) :
            if self.bff[self.bff[i]] == i and i < self.bff[i] :
                alter += lineLen[i] + lineLen[self.bff[i]] + 2
        self.result = max(self.result, alter)

    def findCircle(self, st) :
        isVisited = [False for _ in range(self.num)]
        p = st
        count = 0
        while not isVisited[p] :
            isVisited[p] = True
            p = self.bff[p]
            count += 1
        if p == st :
            return count
        else :
            return 0

    def findLine(self, st) :
        lineLen = [0 for _ in range(self.num)]
        queue = []
        queue.append(st)
        head = 0
        tail = 1
        while head < tail :
            p = queue[head]
            head += 1
            for pp in self.counterBff[p] :
                if pp == st or pp == self.bff[st] or lineLen[pp] > 0 :
                    continue
                lineLen[pp] = lineLen[p] + 1
                queue.append(pp)
                tail += 1
        maxLen = 0
        for _ in range(self.num) :
            maxLen = max(maxLen, lineLen[_])
        return maxLen

    def output(self, caseIndex) :
        stdout.write("Case #%d: %d\n" % (caseIndex, self.result))

if __name__ == "__main__" :
    instance = Solver()
    instance.run()

