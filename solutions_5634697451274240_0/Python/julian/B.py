

#
# @author julian
#
class B:

    __class_name = "B"
    __input_file = __class_name + ".in"
    __output_file = __class_name + ".out"

    __stack = [False for i in range(0, 0)] 


    def run(self):
        input = open(self.__input_file, "r")
        output = open(self.__output_file, "w")
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
        return


    def read(self, input):
        line = input.readline().strip()
        self.__stack = [False for i in range(0, len(line))]
        i = 0
        for ch in line:
            self.__stack[i] = (ch == "+")
            i += 1


    def write(self, output, index, solution):
        output.write("Case #" + str(index + 1) + ": " + solution + "\n")

    
    def flip(self, size) :
        for i in range(0, size):
            self.__stack[i] = not self.__stack[i] 


    def check(self):
        ret = True
        for i in range(0, len(self.__stack)):
            ret = ret and self.__stack[i]
        return ret


    def find_last(self):
        ret = -1
        for i in range(0, len(self.__stack)):
            if (not self.__stack[i]):
                ret = i
        return ret


    def solve(self):
        ret = 0
        while (not self.check()):
            last = self.find_last()
            self.flip(last + 1)
            ret += 1
                                  
        return str(ret)


#
# main
#
main = B()
main.run()


