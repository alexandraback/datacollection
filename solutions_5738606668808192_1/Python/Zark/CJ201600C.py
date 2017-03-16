from sys import stdin, stdout
import math

class Solver :

    def run(self) :
        flag = [True for _ in range(1000000)]
        for i in range(2, 1000000) :
            if flag[i] :
                x = i + i;
                while x < 1000000 :
                    flag[x] = False
                    x += i
        self.primes = []
        for i in range(2, 1000000) :
            if flag[i] :
                self.primes.append(i)

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
        lastItr = 1 << (self.length - 2);
        i = 0
        while i < lastItr :
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
            i += 1

    def check(self, num) :
        #end = int(math.sqrt(num))
        for i in self.primes: # range(2, end + 1) :
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

