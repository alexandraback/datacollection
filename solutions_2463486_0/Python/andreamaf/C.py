#import math
from bisect import bisect, bisect_left

def is_pali(n):
    s = str(n)
    l = len(s)
    if l == 1:
        return True
    return s[:l/2] == s[l-1:(l-1)/2:-1] 

#Memo = [0] * (10 ** 7 +1)
P = [1, 4, 9, 121, 484, 10201, 12321, 14641, 40804, 44944, 1002001, 1234321, 4008004, 100020001, 102030201, 104060401, 121242121, 123454321, 125686521, 400080004, 404090404, 10000200001, 10221412201, 12102420121, 12345654321, 40000800004, 1000002000001, 1002003002001, 1004006004001, 1020304030201, 1022325232201, 1024348434201, 1210024200121, 1212225222121, 1214428244121, 1232346432321, 1234567654321, 4000008000004, 4004009004004]

if __name__ == '__main__':
    
    fi = open('C.in', 'r')
    fo = open('C.out', 'w')
    T = int(fi.readline().strip('\n\r '))
    # Memoize
    #for i in xrange(1, 10 ** 7 + 1):
    #    if is_pali(i):
    #        if is_pali(i * i):
    #            #Memo[i] = Memo[i-1] + 1
    #            print '%d,' % (i * i),
    for ix in xrange(1, T+1):        
        A, B = fi.readline().strip('\n\r ').split(); A = int(A); B = int(B)
        #lA, lB = int(math.ceil(A ** .5)), int(math.floor(B ** .5))
        #ans = Memo[lB] - Memo[lA-1]
        ans = (bisect(P, B)-1) - (bisect_left(P, A)-1)
        fo.write('Case #%d: %d\n' % (ix, ans))
