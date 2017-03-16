__author__ = 'cary shindell'

inp = open("digits.in", 'r')
opt = open("digits.out", 'w')

N = None
strs = []
for line in inp:
    if N is None:
        N = int(line)
    else:
        if "\n" in line:
            line = line[:-1]
        strs.append(line)

results = []

for s in strs:
    newstr = list(s)
    num = ""
    num0s = 0
    num1s = 0
    num2s = 0
    num3s = 0
    num4s = 0
    num5s = 0
    num6s = 0
    num7s = 0
    num8s = 0
    num9s = 0
    while "Z" in newstr:
        newstr.remove("Z")
        newstr.remove("E")
        newstr.remove("R")
        newstr.remove("O")
        num0s += 1
    while "W" in newstr:
        newstr.remove("T")
        newstr.remove("W")
        newstr.remove("O")
        num2s += 1
    while "U" in newstr:
        newstr.remove("F")
        newstr.remove("O")
        newstr.remove("U")
        newstr.remove("R")
        num4s += 1
    while "O" in newstr:
        newstr.remove("O")
        newstr.remove("N")
        newstr.remove("E")
        num1s += 1
    while "F" in newstr:
        newstr.remove("F")
        newstr.remove("I")
        newstr.remove("V")
        newstr.remove("E")
        num5s += 1
    while "X" in newstr:
        newstr.remove("S")
        newstr.remove("I")
        newstr.remove("X")
        num6s += 1
    while "V" in newstr:
        newstr.remove("S")
        newstr.remove("E")
        newstr.remove("V")
        newstr.remove("E")
        newstr.remove("N")
        num7s += 1
    while "G" in newstr:
        newstr.remove("E")
        newstr.remove("I")
        newstr.remove("G")
        newstr.remove("H")
        newstr.remove("T")
        num8s += 1
    while "H" in newstr:
        newstr.remove("T")
        newstr.remove("H")
        newstr.remove("R")
        newstr.remove("E")
        newstr.remove("E")
        num3s += 1
    while "N" in newstr:
        newstr.remove("N")
        newstr.remove("I")
        newstr.remove("N")
        newstr.remove("E")
        num9s += 1
    for x in range(0,num0s):
        num += "0"
    for a in range(0,num1s):
        num += "1"
    for b in range(0,num2s):
        num += "2"
    for c in range(0,num3s):
        num += "3"
    for d in range(0,num4s):
        num += "4"
    for e in range(0,num5s):
        num += "5"
    for f in range(0,num6s):
        num += "6"
    for g in range(0,num7s):
        num += "7"
    for h in range(0,num8s):
        num += "8"
    for i in range(0,num9s):
        num += "9"
    results.append(num)

ctr = 1
for t in results:
    opt.write("Case #" + str(ctr) + ": " + t + "\n")
    ctr += 1

inp.close()
opt.close()

