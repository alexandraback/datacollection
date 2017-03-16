#!/usr/bin/env python

def main():
    inFile = open('in.txt','r')
    outFile = open('out1.txt','w')
    testCase = int(inFile.readline()[:-1])
    for i in range(1, testCase+1, 1):
        string = inFile.readline()[:-1]
        strList = string.split(' ')
        k = int(strList[0])
        c = int(strList[1])
        s = int(strList[2])
        mess = 'Case #' + str(i) + ':'
        outFile.write(mess)
        if s < (k-c+1):
            outFile.write(' IMPOSSIBLE\n')
            continue
        finalVal = k
        if c <= k:
            for i in range(2,c,1):
                finalVal += (i-1)*(k**(c-i))
        else:
            for i in range(2,k,1):
                finalVal += (i-1)*(k**(k-i))
            finalVal = finalVal*(k**(c-k))
        mess = ' ' + str(finalVal)
        for i in range(1,k-c+1,1):
            mess += ' ' + str(finalVal-i)
        mess += '\n'
        outFile.write(mess)
if __name__ == '__main__':
    main()
