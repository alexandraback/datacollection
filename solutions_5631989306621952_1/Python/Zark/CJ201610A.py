from sys import stdin, stdout

class Solver :

    def run(self) :
        caseNum = int(stdin.readline())
        for caseIndex in range(caseNum) :
            self.input()
            self.exe()
            self.output(caseIndex + 1)

    def input(self) :
        self.letters = stdin.readline()

    def exe(self) :
        self.result = []
        for c in self.letters :
            if len(self.result) == 0 :
                self.result.append(c)
            elif ord(c) < ord(self.result[0]) :
                self.result.append(c)
            else :
                self.result.insert(0, c)

    def output(self, caseIndex) :
        stdout.write("Case #%d: %s" % (caseIndex, "".join(self.result)))

if __name__ == "__main__" :
    instance = Solver()
    instance.run()

