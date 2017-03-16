import itertools

def fakeRemove(list, idx):
    dummy = list[:]
    dummy.pop(idx)
    return dummy

def findThings(sumresult, item, List):
    if not List:
        return sumresult
    ninlst = 0
    idx = 0
    for things in List:
        if things[0] == item[-1]:
            ninlst = 1

            sumresult = sumresult + findThings(1, things, fakeRemove(List, idx))
        idx = idx+1

    if (ninlst == 0):
        idx = 0
        for things in List:
            sumresult = sumresult + findThings(0, things, fakeRemove(List, idx))
        idx = idx+1
    return sumresult

def perms02(l):
    sz = len(l)
    if sz<=1: return [l]
    return [p[:i]+[l[0]]+p[i:] for i in range(sz) for p in perms02(l[1:])]

fin = open('B-small-attempt0.in.txt','r')
#fin = open('A-large-practice.in.txt', 'r')
#fin = open('input.txt')

fout = open('output.txt', 'w')

numCases = int(fin.readline())

for cases in range(numCases):
    num = [int(x) for x in fin.readline().split()]
    lst = list(fin.readline().split())

    List = []
    for item in lst:
        item = [item[0], item[-1]]
        List.append(item)


    allPerms = perms02(List)
    sum = 0
    for perm in allPerms:
        length = len(perm)
        bad = 0
        goodLeft = [0]*length
        goodRight = [0]*length

        if length == 1:
            break
        elif length == 2:
            if(perm[0][1]==perm[1][0] and not(perm[0][0] == perm[1][1])):
                sum = sum +1
        else:

            for i in range(1, length):
               if(perm[i][0]==perm[i-1][1]): goodLeft[i] = 1
            for i in range(0, length-1):
               if(perm[i][1]==perm[i+1][0]): goodRight[i] = 1

            for i in range(length):
                if(goodLeft[i]==0):
                    for j in range(length):
                        if(i != j):
                            if(perm[i][0] == perm[j][1]):
                                bad = 1
                                break
                if(bad == 1):
                    print(i, perm)
                    break
                if(goodRight[i]==0):
                    for j in range(length):
                        if(i != j):
                            if(perm[i][1] == perm[j][0]):
                                bad = 1
                                break
                if(bad == 1):
                    break
        if(bad == 0):
            sum = sum +1

    print(sum)


    #fout.write("Case #" + str(cases+1) + ": "+'\n')

fin.close()
fout.close()

