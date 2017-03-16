import sys
sys.path.append('../')

from utils import GCJTemplate as gt

class IJK(object):
    def __init__(self, ch):
        self.ch = ch
        self.op = 1

    def multiply(self, ch):
        if self.ch == '1':
            self.ch = ch
        elif self.ch == 'i':
            if ch == 'i':
                self.ch = '1'
                self.op *= -1
            elif ch == 'j':
                self.ch = 'k'
            elif ch == 'k':
                self.ch = 'j'
                self.op *= -1
        elif self.ch == 'j':
            if ch == 'i':
                self.ch = 'k'
                self.op *= -1
            elif ch == 'j':
                self.ch = '1'
                self.op *= -1
            elif ch == 'k':
                self.ch = 'i'
        elif self.ch == 'k':
            if ch == 'i':
                self.ch = 'j'
            elif ch == 'j':
                self.ch = 'i'
                self.op *= -1
            elif ch == 'k':
                self.ch = '1'
                self.op *= -1

    def pr(self):
        print '==== ',
        if self.op == -1: print '-',
        print self.ch

def solve_str(l, s):
    # print 'solve_str', l, s
    cur = IJK(s[0])
    flag = 0
    for idx in xrange(1, l):
        if flag == 0 and cur.ch == 'i' and cur.op == 1:
            flag = 1
        if flag == 1 and cur.ch == 'k' and cur.op == 1:
            flag = 2
        cur.multiply(s[idx])
    if flag == 0 and cur.ch == 'i' and cur.op == 1:
        flag = 1
    if flag == 1 and cur.ch == 'k' and cur.op == 1:
        flag = 2
    return flag == 2

def solve_imp():
    L, X = gt.read_int()
    S = raw_input()

    cur = IJK(S[0])
    for idx in xrange(1, L):
        cur.multiply(S[idx])

    if cur.ch == '1':
        if cur.op == -1 and X % 2 == 1:
            if X == 1: return solve_str(L, S)
            else: return solve_str(L * 3, ''.join([S] * 3))
        else: return False

    if X % 4 != 2:
        return False
    if X == 2: return solve_str(L * 2, ''.join([S] * 2))
    if X == 6: return solve_str(L * 6, ''.join([S] * 6))
    return solve_str(L * 10, ''.join([S] * 10))

def solve():
    return 'YES' if solve_imp() else 'NO'

gt.GCJJob('C', solve).run(True)
