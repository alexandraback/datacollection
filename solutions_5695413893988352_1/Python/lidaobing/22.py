import sys
import random
sys.setrecursionlimit(10000)

MAX = (99999999999999999999999999999999,)


def cool(i, a):
    ii = str(i)
    ii = '0'*(len(a)-len(ii)) + ii
    for j in range(len(a)):
        if a[j] == '?':
            continue
        if ii[j] != a[j]:
            return False
    return True

def foo2(i, j, n):
    return (abs(i-j), i, j)

def fmt(a, n):
    res = str(a)
    res = '0'*(n-len(res))+res
    return res

def prev(i):
    if i == '0':
        return ''
    return chr(ord(i)-1)

def next(i):
    if i == '9':
        return ''
    return chr(ord(i)+1)


def foo2(a, b, aa, bb):        
    if len(aa) != len(bb):
        return MAX

    if len(a) == 0:
        return (abs(int(aa)-int(bb)), ' '.join([aa, bb]))

    if aa == bb:
        if a[0] == '?' and b[0] == '?':
            return min(
                foo2(a[1:], b[1:], aa+'0', bb+'0'),
                foo2(a[1:], b[1:], aa+'0', bb+'1'),
                foo2(a[1:], b[1:], aa+'1', bb+'0'))

        if a[0] == '?':
            return min(
                foo2(a[1:], b[1:], aa+b[0], bb+b[0]),
                foo2(a[1:], b[1:], aa+prev(b[0]), bb+b[0]),
                foo2(a[1:], b[1:], aa+next(b[0]), bb+b[0]),
                )
        if b[0] == '?':
            return min(
                foo2(a[1:], b[1:], aa+a[0], bb+a[0]),
                foo2(a[1:], b[1:], aa+a[0], bb+prev(a[0])),
                foo2(a[1:], b[1:], aa+a[0], bb+next(a[0])),
                )
        else:
            return foo2(a[1:], b[1:], aa+a[0], bb+b[0])    

    if aa < bb:
        if a[0] == '?' and b[0] == '?':
            return foo2(a[1:], b[1:], aa+'9', bb+'0')
        if a[0] == '?':
            return foo2(a[1:], b[1:], aa+'9', bb+b[0])
        if b[0] == '?':
            return foo2(a[1:], b[1:], aa+a[0], bb+'0')
        else:
            return foo2(a[1:], b[1:], aa+a[0], bb+b[0])    


    if aa > bb:
        if a[0] == '?' and b[0] == '?':
            return foo2(a[1:], b[1:], aa+'0', bb+'9')
        if a[0] == '?':
            return foo2(a[1:], b[1:], aa+'0', bb+b[0])
        if b[0] == '?':
            return foo2(a[1:], b[1:], aa+a[0], bb+'9')
        else:
            return foo2(a[1:], b[1:], aa+a[0], bb+b[0])    



            



def foo(ifile):
    a,b = ifile.readline().split()
    return foo2(a, b, '', '')[1]


def main():
    ifile = sys.stdin
    n = int(ifile.readline())
    for i in range(n):
        print 'Case #%d: %s' % (i+1, foo(ifile))
        sys.stdout.flush()

main()

