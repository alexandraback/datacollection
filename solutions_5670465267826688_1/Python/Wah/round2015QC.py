
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
    #print "before\t", sss
    if sss[0] == '-':
        if len(sss) >= 3:
            #print sss[0:3], ' to ', ijkmap[sss[0:3]]
            sss = ijkmap[sss[0:3]] + sss[3:]
        else:
            sss = ""
    else:
        if len(sss) >= 2:
            #print sss[0:2], ' to ', ijkmap[sss[0:2]]
            sss = ijkmap[sss[0:2]] + sss[2:]
        else:
            sss = ""
#print "after\t", sss
    return sss

def canijkreduce(sss):

    if len(sss) > 0:
        if sss[0] == '-':
            return len(sss) >= 3
        else:
            return len(sss) >= 2
    else:
        return False

import time

def ijkreduceto1(sss):
    while len(sss) > 0:
        if canijkreduce(sss):
            sss = ijkupdate(sss)
        else:
            return False
    return True

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
        startTime = time.time()

        if len(self.S.replace("i", "")) == 0 or len(self.S.replace("j", "")) == 0 or len(self.S.replace("k", "")) == 0:
            self.result = "NO"
        else:
            loop2 = 0
            for i in range(1, min(self.X + 1, 7)):
                if ijkreduceto1(self.S * i):
                    loop2 = i
                    break
            loop = 0
            for i in range(1, min(self.X + 1, 7)):
                if ijkreduce(self.S * i):
                    loop = i
                    break
            if loop == 0:
                self.result = "NO"
            elif self.X == loop:
                self.result = "YES"
            elif (self.X - loop) % (2 * loop) == 0:
                self.result = "YES"
            elif loop2 != 0 and (self.X - loop) % loop2 == 0:
                self.result = "YES"
            else:
                self.result = "NO"
#if (ijkreduce(self.S * self.X)):
#               self.result = "YES"
#           else:
#               self.result = "NO"

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