from sys import stdin, stdout

class Solver :

    def run(self) :
        caseNum = int(stdin.readline())
        for caseIndex in range(caseNum) :
            self.input()
            self.exe()
            self.output(caseIndex + 1)

    def input(self) :
        self.N = int(stdin.readline())
        self.nums = []
        for i in range(self.N * 2 - 1) :
            self.nums.append([int(_) for _ in stdin.readline().split()])

    def exe(self) :
        count = {}
        for i in range(self.N * 2 - 1) :
            for n in self.nums[i] :
                if not n in count :
                    count[n] = 0
                count[n] += 1
        self.result = []
        for n in count :
            if count[n] % 2 == 1 :
                self.result.append(n)
        self.result.sort()

    def output(self, caseIndex) :
        stdout.write("Case #%d:" % (caseIndex))
        for n in self.result :
            stdout.write(" %d" % (n))
        stdout.write("\n")

if __name__ == "__main__" :
    instance = Solver()
    instance.run()

