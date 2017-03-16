#default gcj in file reader
#Boreeas, 7/3/2012
fin = open("in")
fout = open("out", "w")
case = 0

def wrt(out):
    global case
    case += 1
    fout.write("Case #" + str(case) + ": " + str(out) + "\n")

fin.readline()  #skip number-of-cases
while 1:
    line = fin.readline().rstrip()
    if not line:
        break
    [a, b, k] = [int(x) for x in line.split()]
    #bruteforce ahoy
    sol = 0;
    for i in range(a):
        for j in range(b):
            if i&j < k:
                sol += 1
    wrt(sol)

#release handles
fin.close()
fout.close()
