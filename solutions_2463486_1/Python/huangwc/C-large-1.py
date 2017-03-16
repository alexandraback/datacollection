from sys import stdin, stdout
from math import sqrt

stdin = open('C-large-1.in', 'r')
stdout = open('C-large-1.out', 'w')

pal2 = [1,4,9,121,484,10201,12321,14641,40804,44944,1002001
        ,1234321,4008004,100020001,102030201,104060401,121242121
        ,123454321,125686521,400080004,404090404,10000200001
        ,10221412201,12102420121,12345654321,40000800004
        ,1000002000001,1002003002001,1004006004001,1020304030201
        ,1022325232201,1024348434201,1210024200121,1212225222121
        ,1214428244121,1232346432321,1234567654321,4000008000004
        ,4004009004004]

def count_pal2(x):
    cnt = 0
    while cnt < len(pal2) and pal2[cnt] <= x:
        cnt += 1
    return cnt

T = int(stdin.readline().strip())


for t in range(1, T+1):

    (A, B) = [int(x) for x in stdin.readline().strip().split()]

    x = int(sqrt(A-1))+1
    cnt = count_pal2(B) - count_pal2(A-1)

    stdout.write('Case #%d: %d\n' % (t, cnt))

stdin.close()
stdout.close()
