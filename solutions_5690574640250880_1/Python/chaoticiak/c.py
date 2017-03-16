"""
Google Code Jam Qualification Round 2014 Problem C

Author  : chaotic_iak
Language: Python 3.3.4
"""

class IOHandlerObject(object):
    source = "c.in"
    target = "c.out"
    sfile = None
    tfile = None

    def __init__(self):
        self.sfile = open(self.source, "a+")
        self.sfile.seek(0)
        self.tfile = open(self.target, "w+")

    def getInput(self, s = False):
        inputs = self.sfile.readline().strip()
        if not s:
            return inputs.split(" ")
        else:
            return inputs

    def writeOutput(self, s = ""):
        self.tfile.write(s)

IOHandler = IOHandlerObject()
g = IOHandler.getInput
w = IOHandler.writeOutput

############################## SOLUTION ##############################

t = int(g(True))
for i in range(1, t+1):
    w("Case #" + str(i) + ":\n")
    r, c, m = [int(i) for i in g()]
    f = r*c - m

    # case 1: R/C = 1
    if r == 1:
        w("c" + "." * (f-1) + "*" * m + "\n")
    elif c == 1:
        w("c\n" + ".\n" * (f-1) + "*\n" * m)

    # case 2: R/C = 2
    elif r == 2:
        if f == 1:
            w("c" + "*" * (c-1) + "\n" + "*" * c + "\n")
        elif f > 2 and f % 2 == 0:
            w("c" + "." * (f//2 - 1) + "*" * (m//2) + "\n" + "." * (f//2) + "*" * (m//2) + "\n")
        else:
            w("Impossible\n")
    elif c == 2:
        if f == 1:
            w("c*\n" + "**\n" * (r-1))
        elif f > 2 and f % 2 == 0:
            w("c.\n" + "..\n" * (f//2 - 1) + "**\n" * (m//2))
        else:
            w("Impossible\n")

    # case 3: R,C >= 3
    else:
        if f in [2,3,5,7]:
            w("Impossible\n")
        elif f == r*c:
            w("c" + "." * (c-1) + "\n" + ("." * c + "\n") * (r-1))
        elif f == 1:
            w("c" + "*" * (c-1) + "\n" + ("*" * c + "\n") * (r-1))
        elif f <= 2*c and f % 2 == 0:
            w("c" + "." * (f//2 - 1) + "*" * (c - f//2) + "\n" + "." * (f//2) + "*" * (c - f//2) + "\n" + ("*" * c + "\n") * (r-2))
        elif f <= 2*c+3 and f % 2 == 1:
            w("c" + "." * (f//2 - 2) + "*" * (c - f//2 + 1) + "\n" + "." * (f//2 - 1) + "*" * (c - f//2 + 1) + "\n" + "..." + "*" * (c-3) + "\n" + ("*" * c + "\n") * (r-3))
        elif f == 2*c+1:
            w("c" + "." * (c-2) + "*\n" + "." * (c-1) + "*\n" + "..." + "*" * (c-3) + "\n" + ("*" * c + "\n") * (r-3))
        elif f % c != 1:
            w("c" + "." * (c-1) + "\n" + ("." * c + "\n") * (f//c-1) + "." * (f%c) + "*" * (c - f%c) + "\n" + ("*" * c + "\n") * (r - f//c - 1))
        else:
            w("c" + "." * (c-1) + "\n" + ("." * c + "\n") * (f//c-2) + "." * (c-1) + "*\n" + ".." + "*" * (c - 2) + "\n" + ("*" * c + "\n") * (r - f//c - 1))