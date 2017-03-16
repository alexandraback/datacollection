import bisect

def ispalin(x):
    s = str(x)
    return s == s[::-1]

def seed(n, maxx, outlist):
    assert ispalin(n)
    if n > maxx or not ispalin(n*n):
        return
    outlist.append(n*n)

    s = str(n)
    L = len(s)
    left = s[:L//2]
    right = s[L//2:]
    if L%2 == 0:
        seed(int(left + '0' + right), maxx, outlist)
        seed(int(left + '1' + right), maxx, outlist)
        seed(int(left + '2' + right), maxx, outlist)
    else:
        seed(int(left + right[0] + right), maxx, outlist)

maxx = 10**50
squares = []
seed(1, maxx, squares)
seed(2, maxx, squares)
seed(3, maxx, squares)
# print(len(squares))
squares.sort()

ncases = int(input())
for i in range(1, ncases+1):
    A, B = tuple(int(t) for t in input().split())
    ans = bisect.bisect_right(squares, B) - bisect.bisect_right(squares, A-1)
    print('Case #{}: {}'.format(i, ans))
