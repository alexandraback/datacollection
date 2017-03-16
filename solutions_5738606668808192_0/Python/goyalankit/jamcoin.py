#!/usr/bin/env python

def getstr(N,J):
    possible = []
    for odd in range(1,N-1,2):
        for even in range(2,N-1,2):
            possible.append([odd,even])
    for odd1 in range(1,N-1,2):
        for odd2 in range(odd1+2, N-1, 2):
            for even1 in range(2,N-1,2):
                for even2 in range(even1+2,N-1,2):
                    possible.append([odd1,odd2,even1, even2])
                    if len(possible) >= J:
                        break
                if len(possible) >= J:
                    break
            if len(possible) >= J:
                break
        if len(possible) >= J:
            break
    defstr = ' 3 4 5 6 7 8 9 10 11\n'
    defnum = []
    for i in range(N):
        defnum.append(0)
    defnum[0] = 1
    defnum[-1] = 1
    mess = ''
    for i in range(J):
        test = defnum[:]
        for j in possible[i]:
            test[-1-j] = 1
        for x in test:
            mess += str(x)
        mess += defstr
    return mess

def main():
    inFile = open('in.txt', 'r')
    outFile = open('out.txt', 'w')
    test = int(inFile.readline()[:-1])
    for i in range(1, test+1, 1):
        mess = 'Case #' + str(i) + ':\n'
        a = inFile.readline()[:-1]
        nums = a.split(' ')
        N = int(nums[0])
        J = int(nums[1])
        mess += getstr(N,J)
        outFile.write(mess)

if __name__ == '__main__':
    main()
