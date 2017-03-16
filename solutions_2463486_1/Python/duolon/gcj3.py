import math
import bisect

def is_palindrome(x):
    x = str(x)
    for i in range(len(x)):
        if x[i] != x[-(i+1)]:
            return False
    return True

def calc(n):
    ret = 0
    for i in range(1, int(math.sqrt(n))+1):
        if is_palindrome(i) and is_palindrome(i*i):
#            print i*i
            ret += 1
    return ret 

table = None

def calc_cheat(n):
    global table
    if table == None:
        table = map(int, file('gcj3.data').readlines())
    idx = bisect.bisect_right(table, n)
    return idx

def work(case_num):
    A, B = map(int, raw_input().split())
    cA = calc_cheat(A-1)
    cB = calc_cheat(B)
    result = cB - cA
    print "Case #%d: %d" % (case_num+1, result)

if __name__ == '__main__':
#    while (True):
#        x = int(raw_input())
#        print calc(x)

#    print calc(1e15)
    
    T = int(raw_input())
    for t in range(T):
        work(t)