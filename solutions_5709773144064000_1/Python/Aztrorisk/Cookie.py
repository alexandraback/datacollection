from math import *

in1 = open("C:\\Users\\Hoa\\Dropbox\\Programs\\Python\\GoogleCodeJam2014\\B-large.in");
output = open("C:\\Users\\Hoa\\Dropbox\\Programs\\Python\\GoogleCodeJam2014\\B-large.txt", "w");

lines = [line for line in in1]

for i in range(int(lines[0])):
    values = [float(l) for l in lines[i + 1].split()]
    # C = values[0], F = values[1], X = values[2]
    rate = 2.0
    time = values[2] / rate
    totalfarmtimecost = values[0] / rate
    newrate = rate + values[1]
    newtime = totalfarmtimecost + values[2] / newrate
    while (newtime < time):
        rate = newrate
        time = newtime
        totalfarmtimecost += values[0] / rate
        newrate = rate + values[1]
        newtime = totalfarmtimecost + values[2] / newrate
    output.write("Case #%d: %.7f\n"%(i + 1, time));

in1.close()
output.close()
