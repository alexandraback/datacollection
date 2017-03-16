with open("A-large.in.txt") as f:
    x = f.readlines()
    x = [int(i) for i in x]

def numsInDigit(a):
    l = []
    while a:
        digit = a % 10
        a /= 10
        l.append(digit)
    return l

nOfCase = x[0]
testCases = x[1:]
for i,a in enumerate(testCases):
    if a == 0:
        print "Case #%d: INSOMNIA" % (i+1)
    else:
        l = numsInDigit(a) #l is a list
        result = a
        count = 2
        while True:
            s = set(l)
            if len(s)==10:
                break
            else:
                result = a * count
                count += 1
                for x in numsInDigit(result):
                    l.append(x) 
        print "Case #%d: %d" % (i+1,result)







