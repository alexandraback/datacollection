
f = open("A-small-attempt0.in", "r")
o = open("A-small-attempt0.out", "w")

T = int(f.readline().strip())

for j in range(1, T+1):
    o.write("case #{}: ".format(j))
    line = list(f.readline().strip())
    digits = []
    while "Z" in line:
        digits.append(0)
        line.remove("Z")
        line.remove("E")
        line.remove("R")
        line.remove("O")
    while "W" in line:
        digits.append(2)
        line.remove("T")
        line.remove("W")
        line.remove("O")
    while "U" in line:
        digits.append(4)
        line.remove("F")
        line.remove("O")
        line.remove("U")
        line.remove("R")
    while "F" in line:
        digits.append(5)
        line.remove("F")
        line.remove("I")
        line.remove("V")
        line.remove("E")
    while "V" in line:
        digits.append(7)
        line.remove("S")
        line.remove("E")
        line.remove("V")
        line.remove("E")
        line.remove("N")
    while "X" in line:
        digits.append(6)
        line.remove("S")
        line.remove("I")
        line.remove("X")
    while "R" in line:
        digits.append(3)
        line.remove("T")
        line.remove("H")
        line.remove("R")
        line.remove("E")
        line.remove("E")
    while "G" in line:
        digits.append(8)
        line.remove("E")
        line.remove("I")
        line.remove("G")
        line.remove("H")
        line.remove("T")
    while "I" in line:
        digits.append(9)
        line.remove("N")
        line.remove("I")
        line.remove("N")
        line.remove("E")
    while "O" in line:
        digits.append(1)
        line.remove("O")
        line.remove("N")
        line.remove("E")

    o.write("{}\n".format("".join([str(i) for i in sorted(digits)])))

f.close()
o.close()