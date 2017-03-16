import sys

T = int(sys.stdin.readline())
for case in xrange(1, T+1):
    x, y = map(int, sys.stdin.readline().split())
    #print (x, y)
    
    result = ""
    while x > 0:
        result = result + "WE"
        x -= 1
    while x < 0:
        result = result + "EW"
        x += 1
    
    while y > 0:
        result = result + "SN"
        y -= 1
    while y < 0:
        result = result + "NS"
        y += 1
    
    print "Case #"+str(case)+": "+str(result)
