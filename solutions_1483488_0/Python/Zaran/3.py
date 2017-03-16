import sys

file = open(sys.argv[1])
nc = int(file.readline().rstrip())

def neighbours(n):
    s = str(n)
    for i in xrange(1,len(s)):
        yield int(s[i:]+s[:i])

def foo(a,b):
    result = 0
    for i in xrange(a,b):
        list = []
        for j in neighbours(i):
            if j > i and j <= b and j not in list:
                list += [j]
                result +=1
    return result

for i in xrange(nc):
    a,b = map(int,file.readline().rstrip().split())
    print "Case #{}: {}".format(i+1,foo(a,b))
