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

    def get_line(self):
        return self.f_in.readline().strip()

    def get_line_func(self,func):
        return func(self.get_line())

    def get_number(self):
        return self.get_line_func(int)

    def get_numbers(self):
        return self.get_line_func(lambda l:list(map(int,l.split())))

    def do(self):
        self.print_it("\n")



import random


class CodeJamTest(CodeJam):
    def get_random_bit(self,n,j):
        L = [True for i in range(n)]
        while len(self.done) < j:
            for i in range(1,n-1):
                L[i] = (random.random() >= 0.5)
            yield tuple(L)

    def convert_radix(self,S,r):
        rp = 1
        val = 0
        for s in S[::-1]:
            if s:
                val += rp
            rp *= r
        return val

    def get_one_factor(self,n):
        if n % 2 == 0:
            return 2

        i = 3
        while i*i <= n and i < 10000:
            if n % i == 0:
                return i
            i += 2
        return n

    def get_qual(self,S):
        keys = []
        for r in range(2,11):
            n = self.convert_radix(S,r)
            v = self.get_one_factor(n)
            if v == n:
                return
            keys.append(v)
        return keys

    def do(self):
        N,J = self.get_numbers()
        self.done = set()

        forms = " ".join(["{}"]*10)

        self.print_ln()

        for S in self.get_random_bit(N,J):
            keys = self.get_qual(S)
            if keys:
                k = self.convert_radix(S,2)
                if k not in self.done:
                    self.done.add(k)
                    self.print_ln(forms,bin(k)[2:],*keys)







if __name__ == '__main__':
    import sys

    if len(sys.argv) < 2:
        print (__file__, "{input file}")

    else:
        CodeJamTest(sys.argv[1])

