import sys

def processTest():
    N = int(f.readline()[:-1])
    turns = 1
    start = N
    while start>1:
        strstart = str(start)
        strreverse = strstart[::-1]
        reverse = int(strreverse)
        last = int(strstart[-1])
        #print(start,reverse)
        if len(strstart) == len(str(reverse)):
            if (last>1 or start<=reverse):
                start = start-1
            else:
                start = reverse
        else:
            start = start-1
        turns+=1
    return turns

f = open(sys.argv[1],'r')
maxtests = int(f.readline())
testnum = 1
while testnum <= maxtests:
    y = processTest()
    print('Case #'+str(testnum)+': '+ str(y))
    testnum+=1

f.close()
