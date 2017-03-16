#! /usr/bin/env python

from copy import deepcopy as dc

def print_ans(t, ans):
    print("Case #{}: {}".format(t, ans))

SIGN = {
    'i': {'j':0, 'k':1},
    'j': {'i':1, 'k':0},
    'k': {'i':0, 'j':1},
}
NUM = {
    'i': {'j':'k', 'k':'j'},
    'j': {'i':'k', 'k':'i'},
    'k': {'i':'j', 'j':'i'},
}

class Quaternion:
    def __init__(self, num = '1', sign=False):
        self._sign = sign
        self._num = num

    def __eq__(self, q):
        return self._num == q._num and self._sign == q._sign

    def __mul__(self, q):
        sign = self._sign ^ q._sign
        if q._num == '1':
            num = self._num
        elif self._num == '1':
            num = q._num
        elif self._num == q._num:
            num = '1'
            sign ^= 1
        else:
            sign ^= SIGN[self._num][q._num]
            num = NUM[self._num][q._num]
        return Quaternion(num, sign)
    
    def __imul__(self, q):
        return self * q
    
    def __truediv__(self, q):
        sign = self._sign ^ q._sign
        if q._num == '1':
            num = self._num
        elif self._num == '1':
            num = q._num
            sign ^= 1
        elif self._num == q._num:
            num = '1'
        else:
            sign ^= SIGN[self._num][q._num]
            num = NUM[self._num][q._num]
        return Quaternion(num, sign)

    def __itruediv__(self, q):
        return self / q

    def __str__(self):
        out = self._num
        if self._sign:
            out = '-' + out
        return out

    def __repr__(self):
        out = self._num
        if self._sign:
            out = '-' + out
        return out

T = int(input())

Q1 = Quaternion('1')
Q1n = Quaternion('1')
Q1n._sign = True
I = Quaternion('i')
J = Quaternion('j')
K = Quaternion('k')

for t in range(1, T+1):
    l, x = [int(s) for s in input().split()]
    s = [Quaternion(c) for c in input()]
    prod = s[0]
    ss = [s[0]]
    for n in s[1:]:
        prod *= n
        ss.append(prod)

    remain = (x & 3)
    pall = dc(Q1)
    for i in range(remain):
        pall *= prod
    if not pall == Q1n:
        print_ans(t, "No")
        continue

    x = min(x, 16)
    p = dc(Q1)
    iflag = False
    kflag = False
    for n in s * x:
        p *= n
        if not iflag and p == I:
            iflag = True
        if iflag and p == K:
            break
    else:
        print_ans(t, "No")
        continue

    print_ans(t, "YES")
