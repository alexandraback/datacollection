from __future__ import print_function
# Fernando Gonzalez del Cueto
# Google Code Jam 2016
#
# Problem B - Revenge of the Pancakes

import numpy as np

#fname_in = r"test.in"
fname_in = r"B-small-attempt0.in"
# #fname_in = r"A-large.in"

fname_out = fname_in.replace('.in', '.out')

fin = open(fname_in, 'r')
fout = open(fname_out, 'w')

class Stack(object):

    def __init__(self, s):
        # translate string to boolean array
        self.l = np.array([(c=='+') for c in s], dtype=bool)

    def __len__(self):
        return len(self.l)

    def flip(self, k):
        # flips all pancakes
        self.l[0:(k+1)] = ~self.l[0:k+1]

    def isok(self):
        return self.l.all()

    def bottomest_wrong(self):
        return max(np.where(~s.l))[0]

    def __repr__(self):
        s = ''

        for is_happy in self.l:
            if is_happy:
                s += '+'
            else:
                s += '-'
        return s

    def __call__(self, k):
        return s.l[k]

def fun(stack):

    assert isinstance(stack, Stack)

    idxs = range(len(stack))
    idxs.reverse()
    counter = 0
    for k in idxs:
        print(k, stack, counter)
        if stack(k):
            print('do nothing')
        else:
            stack.flip(k)
            counter += 1
            print('flip at %i' % k)
        if stack.isok():
            break

    print(stack, counter)

    return counter

n = int(fin.readline().strip())
for case_j in range(1, n+1):

    s = Stack(fin.readline().strip())

    res = fun(s)
    line_out = "Case #%i: %i\n" % (case_j, res)
    print(line_out, end='')
    fout.write(line_out)

fin.close()
fout.close()

