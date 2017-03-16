__author__ = 'Owen'

def RevengeOfThePancakes(yum):
    pan = ""
    for i in yum:
        if i == "+" or i == "-":
            pan += i

    c = 0
    for i in range(len(pan)-1):
        if pan[1+i] != pan[i]:
            c += 1

    if pan[0] == "+" and c%2 == 0:
        aux = 0
    elif pan[0] == "+" and c%2 == 1:
        aux = 1
    elif pan[0] == "-" and c%2 == 0:
        aux = 1
    else:
        aux = 0

    return str(c + aux)


f = open("C:\Users\Owen\Documents\DEMAT\Google Code Jam\B-small-attempt2.in", "r")
a = []
for line in f:
    a.append(line)

print a
print a[0]


with open("C:\Users\Owen\Documents\DEMAT\Google Code Jam\SolRevengePancakesSmall.txt", "w") as text_file:
    for i in range(int(a[0])):
        text_file.write("Case #%s: %s \n" %(i+1, RevengeOfThePancakes(a[1+i])))


