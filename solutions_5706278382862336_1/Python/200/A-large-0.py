__author__ = 'bowen'

from os.path import splitext
from sys import setrecursionlimit
from math import *

setrecursionlimit(10000)


class MetaClass(type):
    def __init__(cls, name, bases, d):
        type.__init__(cls, name, bases, d)
        #cls.static_variable =


class Solver(object):
    __metaclass__ = MetaClass

    def __init__(self, case_input):
        pass
        self.A, self.B = [float(item) for item in case_input.readline().strip().split('/')]

    def dec2bin(self, f):
        if f >= 1:
            g = int(log(f, 2))
        else:
            g = -1
        h = g + 1
        ig = pow(2, g)
        st = ""
        while f > 0 or ig >= 1:
            if f < 1:
                if len(st[h:]) >= 41:
                    return None
            if f >= ig:
                st += "1"
                f -= ig
            else:
                st += "0"
            ig /= 2
        #st = st[:h] + "." + st[h:]
        st = "." + st[h:]
        return st

    def float_to_binary(self, num):
        exponent=0
        shifted_num=num
        while shifted_num != int(shifted_num):
            shifted_num*=2
            exponent+=1
        if exponent==0:
            return '{0:0b}'.format(int(shifted_num))
        binary='{0:0{1}b}'.format(int(shifted_num),exponent+1)
        #integer_part=binary[:-exponent]
        fractional_part=binary[-exponent:].rstrip('0')
        return '.{0}'.format(fractional_part)

    def solve(self):
        num = self.A / self.B
        if self.A > self.B:
            return -1
        result = self.float_to_binary(self.A / self.B)
        if len(result) > 41:
            return -1
        else:
            return result.find('1')


    def get_result(self):
        result = self.solve()
        #format result to text
        if result < 0:
            result = 'impossible'
        else:
            result = '%d' % result
        return result


def main(case_input, case_output):
    T = int(case_input.readline())
    for i in xrange(1, T + 1):
        result = Solver(case_input).get_result()
        print 'Case #%d: %s' % (i, result)
        case_output.write('Case #%d: %s\n' % (i, result))

current_path = splitext(__file__)[0]
input_path = current_path + '.in'
output_path = current_path + '.out'

with open(output_path, 'w') as outfile:
    with open(input_path, 'r') as infile:
        main(infile, outfile)