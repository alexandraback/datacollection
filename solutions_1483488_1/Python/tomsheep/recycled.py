import sys

def readLine():
    return sys.stdin.readline()

def readLineAsInt():
    return int(readLine())

def readLineAsArray():
    return readLine().split()

def readLineAsIntArray():
    return [int(x) for x in readLineAsArray()]

def shift(s, n):
    return s[-n:] + s[:len(s) - n]

def calcN(num, A, B):
    s = str(num)
    n = len(s);
    arr = []
    for i in range(1, n):
        new_num = int(shift(s, i))
        if num < new_num <= B:
            #print num, new_num
            arr.append(new_num)
    return len(set(arr))
    
def case(A, B):
    ret = 0
    for i in range(A, B):
        ret += calcN(i, A, B)        
    return ret    

T = readLineAsInt()
for i in range(T):
    A, B = readLineAsIntArray();
    ret = case(A, B)
    print "Case #%d: %d" % (i + 1, ret)