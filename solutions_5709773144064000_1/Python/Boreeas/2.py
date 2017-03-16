#default gcj in file reader
#Boreeas, 7/3/2012
fin = open("in")
fout = open("out", "w")
case = 0

def wrt(out):
    global case
    case += 1
    fout.write("Case #" + str(case) + ": " + str(out) + "\n")

def time_to(rate, tgt):
    return tgt / rate

fin.readline()  #skip number-of-cases
while 1:
    line = fin.readline().rstrip()
    if not line:
        break
    # Hook here
    [cost, bonus, tgt] = [float(x) for x in line.split()]
    time = 0
    rate = 2
    while time_to(rate, tgt) > (time_to(rate, cost) + time_to(rate + bonus, tgt)):
        time += time_to(rate, cost)
        rate += bonus
    wrt(time + time_to(rate, tgt))
    




#release handles
fin.close()
fout.close()
