def fillArr(x, y):
    y_ = set(y)
    return [ n+1 if i in y_ else n for i,n in enumerate(x)]

def breakfunc(n):
    return [ (n/10**r)%10 for r in range(len(str(n)))]

T = input()

for j in range(T):
    inp = input()
    # print "Input = %d" % inp 
    if inp == 0:
        print "Case #%d: %s" % (j+1, "INSOMNIA")
        continue
    
    x = [0] * 10
    i = 1
    while 0 in x:
        temp = inp * i
        # print "i=%d temp=%d" % (i,temp)
        x = fillArr(x, breakfunc(temp))
        i = i+1
    print "Case #%d: %d" % (j+1, temp)
