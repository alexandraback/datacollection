from sys import stdin, stdout

class Solver :

    def run(self) :
        caseNum = int(stdin.readline())
        for caseIndex in range(caseNum) :
            self.input()
            self.exe()
            self.output(caseIndex + 1)

    def input(self) :
        line = stdin.readline()
        self.stack = []
        for _ in line :
            if _ == "+" :
                self.stack.append(1)
            elif _ == "-" :
                self.stack.append(0)

    def exe(self) :
        self.result = 0
        for i in range(len(self.stack) - 1, -1, -1) :
            if self.stack[i] == 0 :
                self.result += 1
                for j in range(i) :
                    self.stack[j] ^= 1

    def output(self, caseIndex) :
        stdout.write("Case #%d: %d\n" % (caseIndex, self.result))

if __name__ == "__main__" :
    instance = Solver()
    instance.run()

