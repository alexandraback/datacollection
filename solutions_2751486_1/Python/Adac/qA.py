import time,string
from math import *

################# Helper Function ##########################
def splitInput(filename):
    inFile = open(filename,'r')
    inPut = inFile.read()
    inPut = inPut.split('\n')
    T = int(inPut[0])

    Cases = inPut[1:]
    emt = Cases.count('')
    for h in range(emt):
        Cases.remove('')
    inFile.close()

    return (T,Cases)

def outputResult(name,stuffs,typ = '.in'):
    output = open(name+typ,'w')
    output.write(stuffs)
    output.close()
    return

def organiseOutputs(caseNumber,singleOutput):
    
    return 'Case #%d:' % (caseNumber) + " "+str(singleOutput)+'\n'

def addEachToElement(initial,addend):
    hld = []
    ct = -1
    same = type([1,2]) == type(initial[0])
    for elm in initial:
        ct += 1
        if same:
            elm.append(addend[ct])
            hld.append(elm)
        else:
            hld.append([elm,addend[ct]])
    return hld


def str2num(strg,typ = 'i'):
    alist = strg.split(' ')
    newList = []
    for item in alist:
        if item != ' ':
            
            if typ == 'i':
                newList.append(int(item))
            else:
                newList.append(float(item))
    return newList

####################### Main Code ##############################

def probA(filename,outputname):
    T,Cases = splitInput(filename)
    allRet = ''
    t1 = time.clock()
    for k in range(T):
        NameN = Cases.pop(0).split(' ')
        name = NameN[0]
        n = int(NameN[1]);
        
        ret = solver(name,n)
        #print k+1
        allRet += organiseOutputs(k+1,ret)
    t2 = time.clock()
    print t2-t1
    outputResult(outputname,allRet[0:-1],typ = '.in')




def solver(name,n):
    cName = converter(name)
    ct = cName.count(1)
    if ct < n : return 0
    fd = finder(cName,n)
    sz = len(cName)
    sp = 0
    ct = 0
    for k in fd:
        ft = k-sp+1
        bk = sz-(k+n)+1
        ct += ft*bk
        sp = k+1

    return ct
    


def converter(name):
    con = 'bcdfghjklmnpqrstvwxyz'
    vow = 'aeiou'
    nm = []
    for k in name:
        if k in vow:
            nm.append(0)
        else:
            nm.append(1)
    return nm

def finder(cname,n):
    pos = 0
    st = []
    ct = 0
    for k in cname:
        pos += 1
        if k == 1:
            if ct == 0 and len(st)>0 and (pos-st[-1]) == (n+1):
                st.append(pos-n)
                ct = 0
            else:
                ct += 1
                if ct == n:
                    st.append(pos-n)
                    ct = 0
        else:
            ct = 0

    return st
    
    
    
    
        


####################### Run Code #############################
    
small = 'A-small-attempt0.in'
large = 'A-large.in'
test = 'test.txt'
smallOut = 'resultA1'
largeOut = 'resultA2'
testOut = 'testResult'

filename = large
outputname = largeOut

probA(filename,outputname)
            
        
    
    
