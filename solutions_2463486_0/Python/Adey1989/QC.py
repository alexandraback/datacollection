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
fairs = getfair(1000)
T = int(f.readline())

for test in range(T):
    a, b = map(int,f.readline().split())
    count = len([val for val in range(a,b+1) if val in fairs])

    print "Case #%d: " % (test+1) + str( count)