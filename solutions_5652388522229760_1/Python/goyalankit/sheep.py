#!/usr/bin/env python

def sepNum(N):
    l = []
    while N != 0:
        l.append(N%10)
        N = N/10
    return l

def main():
    inFile = open('in.txt', 'r')
    outFile = open('out.txt', 'w')
    testCase = int(inFile.readline()[:-1])
    for i in range(1,testCase+1, 1):
        req = [0,1,2,3,4,5,6,7,8,9]
        N = int(inFile.readline()[:-1])
        mess = 'Case #' + str(i) + ': '
        outFile.write(mess)
        if N == 0:
            outFile.write('INSOMNIA\n')
            continue
        iterate = 1
        while len(req) != 0:
            numList = sepNum(iterate*N)
            for x in numList:
                try:
                    req.remove(x)
                except ValueError:
                    pass
            iterate += 1
        iterate -= 1
        outFile.write(str(iterate*N)+ '\n')


if __name__=='__main__':
    main()
