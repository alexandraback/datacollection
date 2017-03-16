import math

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
#            print n, i*i, i
            ret += 1
    return ret 

def work(case_num):
    A, B = map(int, raw_input().split())
    cA = calc(A-1)
    cB = calc(B)
    result = cB - cA
    print "Case #%d: %d" % (case_num+1, result)

if __name__ == '__main__':
#    while (True):
#        x = int(raw_input())
#        print calc(x)
    
    
    T = int(raw_input())
    for t in range(T):
        work(t)