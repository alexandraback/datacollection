from math import *
import sys

in1 = open("C:\\Users\\Hoa\\Dropbox\\Programs\\Python\\GoogleCodeJam2014\\C-large.in");
output = open("C:\\Users\\Hoa\\Dropbox\\Programs\\Python\\GoogleCodeJam2014\\C-large.txt", "w");

lines = [line for line in in1]

def write(s):
    output.write(s)

def solve(r, c, mines):
    free = r * c - mines
    dots = free - 1
    if free == 1:
        for i in range(r):
            for j in range(c):
                if i == 0 and j == 0:
                    write("c")
                else:
                    write("*")
            write("\n")
    elif r == 1 or c == 1:
        for i in range(r):
            for j in range(c):
                if i == 0 and j == 0:
                    write("c")
                elif dots != 0:
                    write(".")
                    dots -= 1;
                else:
                    write("*")
            write("\n")
    elif free == 2 or free == 3 or free == 5 or free == 7:
        write("Impossible\n")
    elif free % 2 == 1:
        if r == 2 or c == 2:
            write("Impossible\n")
            return
        # handle ODD cases where r and c is at least 3 and free is at least 9
        bigger = max(r,c)
        smaller = min(r,c)
        ar = 2
        ac = (free - 3) / 2
        excess = 3
        if ac > bigger:
            excess = free - ar * bigger
            if excess == 1:
                excess = 3
                ac = bigger - 1
            else:
                ac = bigger
        devrows = excess / ac
        devspace = excess % ac
        watch = False
        if (devspace == 1):
            watch = True
            
        if smaller == c:
            ar = ac
            ac = 2
        for i in range(r):
            for j in range(c):
                if i == 0 and j == 0:
                    write("c")
                elif ac == 2 and i < ar and j < ac + devrows:
                    if j == ac + devrows - 1 and i == ar - 1 and watch:
                        write("*")
                    else:
                        write(".")
                elif ac == 2 and i < devspace and j == ac + devrows:
                    write(".")
                elif ac == 2 and i == devspace and j == ac + devrows and watch:
                    write(".")

                elif ar == 2 and i < ar + devrows and j < ac:
                    if i == ar + devrows - 1 and j == ac - 1 and watch:
                        write("*")
                    else:
                        write(".")
                elif ar == 2 and i == ar + devrows and j < devspace:
                    write(".")
                elif ar == 2 and i == ar + devrows and j == devspace and watch:
                    write(".")
                else:
                    write("*")
            write("\n")
    else:
        # handle EVEN cases where r and c is at least 3 and free is at least 9 
        bigger = max(r,c)
        smaller = min(r,c)
        ar = 2
        ac = free / 2
        excess = 0
        if ac > bigger:
            excess = free - ar * bigger
            ac = bigger
        devrows = excess / bigger
        devspace = excess % bigger
        watch = False
        if (devspace == 1):
            watch = True
            
        if smaller == c:
            ar = ac
            ac = 2
        for i in range(r):
            for j in range(c):
                if i == 0 and j == 0:
                    write("c")
                elif ac == 2 and i < ar and j < ac + devrows:
                    if j == ac + devrows - 1 and i == ar - 1 and watch:
                        write("*")
                    else:
                        write(".")
                elif ac == 2 and i < devspace and j == ac + devrows:
                    write(".")
                elif ac == 2 and i == devspace and j == ac + devrows and watch:
                    write(".")

                elif ar == 2 and i < ar + devrows and j < ac:
                    if i == ar + devrows - 1 and j == ac - 1 and watch:
                        write("*")
                    else:
                        write(".")
                elif ar == 2 and i == ar + devrows and j < devspace:
                    write(".")
                elif ar == 2 and i == ar + devrows and j == devspace and watch:
                    write(".")
                else:
                    write("*")
            write("\n")

for i in range(int(lines[0])):
    data = [int(l) for l in lines[i + 1].split()]
    write("Case #%d:\n"%(i + 1))
    solve(data[0],data[1],data[2])

in1.close()
output.close()
