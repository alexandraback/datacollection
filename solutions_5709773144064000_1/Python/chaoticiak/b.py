"""
Google Code Jam Qualification Round 2014 Problem B

Author  : chaotic_iak
Language: Python 3.3.4
"""

class IOHandlerObject(object):
    source = "b.in"
    target = "b.out"
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
    w("Case #" + str(i) + ": ")
    c, f, x = [float(i) for i in g()]

    sm = 0
    p = 2
    curr = c/p + x/(p+f)
    while c/p + x/(p+f) < x/p:
        sm += c/p
        p += f
    sm += x/p
    w(str(sm) + "\n")