

#
# @author julian
#
class A:

    __className = "A"
    __inputFile = __className + ".in"
    __outputFile = __className + ".out"

    __ndig = 10
    __n = 0
    __digits = [False for i in range(0, __ndig)] 


    def run(self):
        input = open(self.__inputFile, "r")
        output = open(self.__outputFile, "w")
        self.execute(input, output)
        input.close()
        output.close()


    def execute(self, input, output):
        t = int(input.readline())
        self.precompute()
        for index in range(0, t):
            self.reset()
            self.read(input)
            self.write(output, index, self.solve())
        output.flush()


    def precompute(self):
        return


    def reset(self):
        self.__digits = [False for i in range(0, self.__ndig)] 
        return


    def read(self, input):
        self.__n = int(input.readline())
        return


    def write(self, output, index, solution):
        output.write("Case #" + str(index + 1) + ": " + solution + "\n")


    def count(self, number):
        numstr = str(number)
        for ch in numstr:
            chpos = int(ch)
            self.__digits[chpos] = True
        return


    def check(self):
        ret = True
        for i in range(0, self.__ndig):
            ret = ret and self.__digits[i]
        return ret


    def solve(self):
        ret = "INSOMNIA"
        if (self.__n > 0):
            c = self.__n
            found = False
            while (not found):
                self.count(c)
                if (self.check()):
                    ret = str(c)
                    found = True
                else:
                    c += self.__n
        return ret


#
# main
#
main = A()
main.run()


