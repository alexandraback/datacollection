
testCaseIndex = 0

ijkmap = {}
ijkmap["ii"] = "-";
ijkmap["ij"] = "k";
ijkmap["ik"] = "-j";
ijkmap["ji"] = "-k";
ijkmap["jj"] = "-";
ijkmap["jk"] = "i";
ijkmap["ki"] = "j";
ijkmap["kj"] = "-i";
ijkmap["kk"] = "-";

ijkmap["-ii"] = "";
ijkmap["-ij"] = "-k";
ijkmap["-ik"] = "j";
ijkmap["-ji"] = "k";
ijkmap["-jj"] = "";
ijkmap["-jk"] = "-i";
ijkmap["-ki"] = "-j";
ijkmap["-kj"] = "i";
ijkmap["-kk"] = "";

def ijkupdate(sss):
    #print "before", sss
    if sss[0] == '-':
        if len(sss) >= 3:
            sss = ijkmap[sss[0:3]] + sss[3:]
        else:
            sss = ""
    else:
        if len(sss) >= 2:
            sss = ijkmap[sss[0:2]] + sss[2:]
        else:
            sss = ""
#print "after", sss
    return sss

def canijkreduce(sss):
    if len(sss) > 0:
        if sss[0] == '-':
            return len(sss) >= 3
        else:
            return len(sss) >= 2
    else:
        return False

def ijkreduce(sss):
    global ijkmap

    step = 0

    while len(sss) > 0:
        if step == 0:
            while len(sss) > 0 and sss[0] != 'i':
                if canijkreduce(sss):
                    sss = ijkupdate(sss)
                else:
                    return False
            sss = sss[1:]
            step += 1
        elif step == 1:
            while len(sss) > 0 and sss[0] != 'j':
                if canijkreduce(sss):
                    sss = ijkupdate(sss)
                else:
                    return False
            sss = sss[1:]
            step += 1
        elif step == 2:
            while len(sss) > 0 and sss[0] != 'k':
                if canijkreduce(sss):
                    sss = ijkupdate(sss)
                else:
                    return False
            sss = sss[1:]
            step += 1
            break

    if len(sss) == 0:
        return step == 3

    while len(sss) > 0:
        if canijkreduce(sss):
            sss = ijkupdate(sss)
        else:
            return False
    return True

class TestCase:
    def __init__(self):
        global testCaseIndex
        testCaseIndex += 1

    def parseInput(self):
        self.L, self.X = raw_input().split(" ")
        self.L = int(self.L)
        self.X = int(self.X)
        self.S = raw_input()

    def generateOutput(self):
        if (ijkreduce(self.S * self.X)):
            self.result = "YES"
        else:
            self.result = "NO"
        print "Case #%d: %s" % (testCaseIndex, self.result)
        
def execTestCase():

    testcases = int(raw_input())
    for i in range(testcases):
        testCase = TestCase()
        testCase.parseInput()
        testCase.generateOutput()

import sys

if len(sys.argv) > 1:
    print ijkreduce(sys.argv[1])
else:
    execTestCase()