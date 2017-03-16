import sys

fas = [0, 1, 4, 9, 121, 484, 10201, 12321, 14641, 40804, 44944, 1234321, 121242121, 123454321, 125686521, 12345654321, 1232346432321, 1234567654321, 123456787654321]

cases = int(sys.stdin.readline())

for case_num in range(1,cases+1):
    a,b = [int(x) for x in sys.stdin.readline().split(" ")]
    i = 0
    while fas[i] < a:
        i+=1
    j = i
    while fas[j] <= b:
        j += 1
    print "Case #%d: %d"%(case_num,j-i)
