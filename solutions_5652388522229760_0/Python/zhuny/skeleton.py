# -*- coding:utf8

# Python3
# zhuny@kaist.ac.kr


import time


class Timer():
    def __init__(self,name):
        self.name = name
        self.start = 0.0

    def __enter__(self):
        self.start = time.time()

    def __exit__(self,ty,va,tr):
        print (self.name,time.time()-self.start)


class CodeJam():
    def __init__(self,input_data):
        output_data = self.get_output(input_data)
        with open(input_data) as f_in:
            with open(output_data,"w") as f_out:
                self.f_in = f_in
                self.f_out = f_out
                n = int(f_in.readline())
                with Timer("CodeJam Time :"):
                    for i in range(1,n+1):
                        self.print_it("Case #{0}: ",i)
                        self.do()

    def print_it(self,string="",*argv,**kwargs):
        string = string.format(*argv,**kwargs)
        print (string, end="")
        self.f_out.write(string)

    def print_ln(self,string="",*argv,**kwargs):
        self.print_it(string + "\n", *argv, **kwargs)

    def get_output(self,name):
        name_s = name.rsplit(".")
        name_s[-1] = "out"
        return ".".join(name_s)

    def get_line_func(self,func):
        return func(self.f_in.readline())

    def get_number(self):
        return self.get_line_func(int)

    def get_numbers(self):
        return self.get_line_func(lambda l:list(map(int,l.split())))

    def do(self):
        self.print_it("\n")




class CodeJamTest(CodeJam):
    def do(self):
        i = self.get_number()

        if i == 0:
            self.print_ln("INSOMNIA")
            return

        S = set()
        c = i

        while True:
            S.update(str(c))
            if len(S) == 10:
                self.print_ln("{0}", c)
                return
            c += i





if __name__ == '__main__':
    import sys

    if len(sys.argv) < 2:
        print (__file__, "{input file}")

    else:
        CodeJamTest(sys.argv[1])

