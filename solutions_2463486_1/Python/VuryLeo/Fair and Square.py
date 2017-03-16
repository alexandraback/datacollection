import sys
import math

def isFair(i):
    mstr=str(i)
    if mstr==mstr[::-1]:
        return True
    return False

if __name__=='__main__':
    #numList = []
    #low, high = 1, 10**14
    #for i in range(int(math.ceil(low ** 0.5)), int(high ** 0.5) + 1):
    #    if isFair(i) and isFair(i ** 2):
    #        numList.append(i)
    numList = [1, 2, 3, 11, 22, 101, 111, 121, 202, 212, 1001, 1111, 2002, 10001, 10101, 10201, 11011, 11111, 11211, 20002, 20102, 100001, 101101, 110011, 111111, 200002, 1000001, 1001001, 1002001, 1010101, 1011101, 1012101, 1100011, 1101011, 1102011, 1110111, 1111111, 2000002, 2001002]
    t = int(sys.stdin.readline())
    for i in range(t):
        sys.stdout.write("Case #{}: ".format(i + 1))
        low, high = tuple(map(int, sys.stdin.readline().split()))
        low, high = int(math.ceil(low ** 0.5)), int(high ** 0.5)
        lowPos, highPos = -1, -1
        for i in range(len(numList)):
            if numList[i] < low:
                lowPos = i
            if numList[i] <= high:
                highPos = i
            else:
                break
        sys.stdout.write('{}\n'.format(highPos - lowPos))

