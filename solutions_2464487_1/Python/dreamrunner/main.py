import math
import time

start_time = time.clock()

def isP(num):
    source = num
    target = 0
    while num > 0:
        target *= 10
        target += num % 10
        num /= 10
    return source==target


fin = open('test.in', 'r')
fout = open('test.out', 'w')
length = int(fin.readline())

for i in range(1, length+1):
    r, t = [int(x) for x in fin.readline().split()]
    a = ((2*r -1)*(2*r -1) + 8 * t)
    result = (int(a**0.5 - (2*r - 1)) / 4)
    if (2*r + 2*result -1)*result > t:
        while (2*r + 2*result -1)*result > t:
            result -= 1
    else:
        while (2*r + 2*result -1)*result <= t:
            result += 1
        result -= 1
    print result
    fout.write("Case #" + str(i) + ": " + str(result) + "\n")

fin.close()
fout.close()

end_time = time.clock()
print "time",end_time-start_time