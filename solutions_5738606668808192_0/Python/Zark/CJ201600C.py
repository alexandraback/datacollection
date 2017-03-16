from sys import stdin, stdout
import math

class Solver :

    def run(self) :
        caseNum = int(stdin.readline())
        for caseIndex in range(caseNum) :
            self.input()
            self.exe()
            self.output(caseIndex + 1)

    def input(self) :
        self.length, self.num = (int(_) for _ in stdin.readline().split())

    def exe(self) :
        count = 0
        self.result = []
        for i in range(1 << (self.length - 2)) :
            digits = []
            digits.append(1)
            tmp = i
            for j in range(self.length - 2) :
                digits.append(tmp % 2)
                tmp = int(tmp / 2)
            digits.append(1)

            isAcc = True
            divides = []
            for j in range(2, 11) :
                num = 0
                e = 1
                for d in digits :
                    num += d * e
                    e *= j
                divides.append(self.check(num))
                if divides[-1] == 0 :
                    isAcc = False
                    break
            if isAcc :
                self.result.append((digits, divides))
                count += 1
                if count == self.num :
                    return

    def check(self, num) :
        end = int(math.sqrt(num))
        for i in range(2, end + 1) :
            if num % i == 0 :
                return i
        return 0

    def output(self, caseIndex) :
        stdout.write("Case #%d:\n" % (caseIndex))
        for digits, divides in self.result :
            for i in range(self.length - 1, -1, -1) :
                stdout.write("%d" % (digits[i]))
            for d in divides :
                stdout.write(" %d" % (d))
            stdout.write("\n")

if __name__ == "__main__" :
    instance = Solver()
    instance.run()

