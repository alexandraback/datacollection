"""
Google Code Jam 2014 Round 1B Problem B

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

    def getInput(self, mode=2):
        # 0: String
        # 1: List of strings
        # 2: List of integers
        inputs = self.sfile.readline().strip()
        if mode == 0:
            return inputs
        if mode == 1:
            return inputs.split()
        if mode == 2:
            return [int(x) for x in inputs.split()]

    def writeOutput(self, s="\n"):
        if isinstance(s, list): s = " ".join(s)
        self.tfile.write(s)

IOHandler = IOHandlerObject()
g = IOHandler.getInput
w = IOHandler.writeOutput

############################## SOLUTION ##############################
t, = g()
for qq in range(t):
    w("Case #" + str(qq+1) + ": ")
    a,b,k = g()
    ct = 0
    for i in range(a):
        for j in range(b):
            if i & j < k: ct += 1
    w(str(ct))
    w()