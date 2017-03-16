#!/usr/bin/env python

def nFlips(stack, out='+'):
    if len(stack) == 1:
        return int(stack != out)
    return (nFlips(stack[:-1], stack[-1]) + int(stack[-1] != out))

def main():
    inputFile = open('in.txt', 'r')
    outFile = open('out.txt', 'w')
    testCases = int(inputFile.readline()[:-1])
    for i in range(1, testCases+1, 1):
        mess = 'Case #' + str(i) + ': ' + str(nFlips(inputFile.readline()[:-1])) + '\n'
        outFile.write(mess)

    inputFile.close()
    outFile.close()

if __name__ == '__main__':
    main()
