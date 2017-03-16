import sys

def get_line():
    return sys.stdin.readline().strip()

def read_nums():
    return [int(item) for item in get_line().split(" ")]

def checkPalindrom(val):
    if val <= 0:
        return False
    inv = 0
    val2 = val
    while val > 0:
        inv = (inv*10) + val%10
        val /= 10
    return val2 == inv

def makePalindrom(val, pos, odd_size):
    res = val
    pos2 = pos*10
    if odd_size:
        pos /= 10
    while pos > 0:
        num = val / pos % 10
        res += num * pos2
        pos /= 10
        pos2 *= 10
    return res

def solve2(up_to):
    res = 0
    for val in palin_list:
        if val > up_to:
            break
        res += 1
    return res

def solve(A, B):
    return solve2(B) - solve2(A-1)

def search(up_to, current, pos, palin_list):
    if pos/10 > up_to:
        return
    flag = False
    palin = makePalindrom(current, pos/10, False)
    val = palin*palin
    if checkPalindrom(val):
        palin_list.append(val)
        flag = True
    palin = makePalindrom(current, pos/10, True)
    val = palin*palin
    if checkPalindrom(val):
        palin_list.append(val)
        flag = True
    if current > 0 and not flag:
        return
    for i in range(0, 3+1):
        search(up_to, current+i*pos, pos*10, palin_list)



palin_list = []
search((10**26)+1, 0, 1, palin_list)
palin_list.sort()

(T,) = read_nums()
for t in xrange(1, T+1):
    (A, B) = read_nums()
    print "Case #%d: %d" % (t, solve(A, B))

