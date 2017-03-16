__author__ = 'Clapika'

fin = open('input', "r+")
fout = open('output', "w")

n = int(fin.readline())
lines = [fin.readline().split() for x in range(n)]
for i in range(len(lines)):
    line = lines[i]
    c = float(line[0])
    f = float(line[1])
    x = float(line[2])
    current_speed = 2
    time = 0
    while x / current_speed > c / current_speed + x / (current_speed + f):
        time += c / current_speed
        current_speed += f
    print(current_speed, time)
    time += x / current_speed
    fout.write("Case #%d: %0.7f\n" % (i + 1, time))