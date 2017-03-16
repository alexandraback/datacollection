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

    def exe(self) :
        if self.num == 0 :
            self.result = -1
            return

        digits = [0 for _ in range(10)]
        count = 10
        index = 1
        while True :
            n = self.num * index
            while n :
                d = n % 10
                n = int(n / 10)
                if digits[d] == 0 :
                    digits[d] = 1
                    count -= 1
            if count == 0 :
                self.result = self.num * index
                break
            index += 1

    def output(self, caseIndex) :
        stdout.write("Case #%d: " % (caseIndex))
        if self.result < 0 :
            stdout.write("INSOMNIA\n")
        else :
            stdout.write("%d\n" % (self.result))

if __name__ == "__main__" :
    instance = Solver()
    instance.run()

