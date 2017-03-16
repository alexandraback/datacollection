from sys import stdin, stdout

class Solver :

    def run(self) :
        caseNum = int(stdin.readline())
        for caseIndex in range(caseNum) :
            self.input()
            self.exe()
            self.output(caseIndex + 1)

    def input(self) :
        self.K, self.C, self.S = (int(_) for _ in stdin.readline().split())

    def exe(self) :
        return

    def output(self, caseIndex) :
        stdout.write("Case #%d:" % (caseIndex))
        for i in range(self.S) :
            stdout.write(" %d" % (i + 1))
        stdout.write("\n")

if __name__ == "__main__" :
    instance = Solver()
    instance.run()

