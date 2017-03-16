

# -*- coding: utf-8 -*-

    
import math

def jobRun(r, t):
    r=float(r)
    t=float(t)
    x =(math.sqrt(4*r*(r -1) + 8*t+1) - 2*r - 3)/4.0
    y = x+1
    return int(math.floor(y))
    


def getinput(inputSize):
    file = r'C:\ewy\A-{inputSize}.in'.format(inputSize=inputSize)
    return open(file, 'r')

def saveoutput(inputSize, results):
    resFile = r'C:\ewy\A-{inputSize}.out'.format(inputSize=inputSize)
    with open(resFile, 'w') as f:
        f.writelines(results)



def main():
    inputSize = 'large'
    f = getinput(inputSize)
    with f:
        N = int(f.readline())
        print 'N:', N
        
        resLines = ''
        for case in range(1,N+1):
            r, t = f.readline().strip().split()
        
            res = jobRun(r, t)
        
            resLine = 'Case #{case}: {res}'.format(case=case, res=res)
            print resLine
            resLines +=resLine + '\n'
            
    saveoutput(inputSize, resLines)
