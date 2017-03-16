import urllib2
import bisect
import math

def search(list, x):
    n = len(list)
    if n == 1:
        return int(x > list[0])
    else:
        mid = n/2
        if x <= list[mid]:
            return search(list[:mid], x)
        else:
            return search(list[mid:], x) + mid

def isSquareOfPalin(n):
    s = int(math.sqrt(n))
    string = str(s)
    m = len(string)
    for i in range(m/2):
        if string[i] != string[m-1-i]:
            return False
            break
    else:
        return True

response = urllib2.urlopen('http://oeis.org/A002779/b002779.txt')
# Yup, I googled it.

pairs = (response.read()).split("\n")
fairAndSquares = []

for p in pairs[:-1]:
    x = int(p.split(' ')[1])
    if isSquareOfPalin(x):
        fairAndSquares.append(x)   

f = open("dataIn.txt", 'r')
g = open("dataOut.txt", 'w')

t = int(f.readline())

for i in range(t):
    line = f.readline()
    a, b = (int(x) for x in line.split(' '))
    l = search(fairAndSquares, a)
    r = search(fairAndSquares, b)
    result = r-l
    if b == fairAndSquares[r]:
        result += 1
    g.write("Case #" + str(i+1) + ": " + str(result) + '\n')
f.close()
g.close()

print "Done."
