from math import *

in1 = open("C:\\Users\\Hoa\\Dropbox\\Programs\\Python\\GoogleCodeJam2014\\D-large.in");
output = open("C:\\Users\\Hoa\\Dropbox\\Programs\\Python\\GoogleCodeJam2014\\D-large.out", "w");

lines = [line for line in in1]

def getDeceitful(naomi, ken, length):
    i = 0
    j = 0
    c = 0
    while i != length:
        while (naomi[i] < ken[j]):
            i += 1
            if (i == length):
                return c
        if (naomi[i] > ken[j]):
            c += 1
            i += 1
            j += 1
    return c
        
for i in range(int(lines[0])):
    naomi = [float(l) for l in lines[i * 3 + 2].split()]
    ken = [float(l) for l in lines[i * 3 + 3].split()]
    length = int(lines[i * 3 + 1])
    naomi.sort()
    ken.sort()
    deceitful = getDeceitful(naomi, ken, length)
    honest = length - getDeceitful(ken, naomi, length)
    output.write("Case #%d: %d %d\n"%(i + 1, deceitful, honest))

in1.close()
output.close()
