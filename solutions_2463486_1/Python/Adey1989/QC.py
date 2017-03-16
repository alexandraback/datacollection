import sys
def ispallindrome(x):
    if str(x)==str(x)[::-1]:
        return 1
    return 0

def getfair(x):
    ans = []
    for i in range(x):
        if ispallindrome(i)==1:
            if ispallindrome(i*i)==1:
                ans.append(i*i)
    return ans

f = open(sys.argv[1])
fairs = [1, 4, 9, 121, 484, 10201, 12321, 14641, 40804, 44944, 1002001, 1234321, 4008004, 100020001, 102030201, 104060401, 121242121, 123454321, 125686521, 400080004, 404090404, 10000200001L, 10221412201L, 12102420121L, 12345654321L, 40000800004L, 1000002000001L, 1002003002001L, 1004006004001L, 1020304030201L, 1022325232201L, 1024348434201L, 1210024200121L, 1212225222121L, 1214428244121L, 1232346432321L, 1234567654321L, 4000008000004L, 4004009004004L, 100000020000001L, 100220141022001L, 102012040210201L, 102234363432201L, 121000242000121L, 121242363242121L, 123212464212321L, 123456787654321L, 400000080000004L]

T = int(f.readline())

for test in range(T):
    a, b = map(int,f.readline().split())
    count = len([val for val in fairs if (val>=a and val<=b)])

    print "Case #%d: " % (test+1) + str( count)