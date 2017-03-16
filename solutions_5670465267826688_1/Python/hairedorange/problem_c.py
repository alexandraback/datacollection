import sys


table = {
    1 : {1 : 1, 2 : 2, 3 : 3, 4: 4},
    2 : {1 : 2, 2 : -1, 3 : 4, 4: -3},
    3 : {1 : 3, 2 : -4, 3 : -1, 4: 2},
    4 : {1 : 4, 2 : 3, 3 : -2, 4: -1}
}


def istrue(length, repeat, string):
    one = 1
    for i in string:
        if one < 0 :
            one = - table[-one][i]
        else:
            one = table[one][i]
    if one == 1:
        return "No"
    elif one == -1:
        loop = 2
    else:
        loop = 4
    buff = 1
    target1 = 2
    target2 = table[2][3]
    target3 = table[target2][4]
    for i in range(min(loop, repeat) * length):
        if buff < 0:
            buff = - table[-buff][string[i%length]]
        else:
            buff = table[buff][string[i%length]]
        if buff == target1:
            target1 = 0
            break
    if target1 != 0:
        return "No"
    for j in range(i+1, min(i+loop*length, repeat *length)):
        if buff < 0:
            buff = - table[-buff][string[j%length]]
        else:
            buff = table[buff][string[j%length]]
        if buff == target2:
            target2 = 0
            break
    if target2 != 0:
        return "No"
    if j == repeat * length -1:
        return "No"
    elif repeat%loop == loop/2:
        return "Yes"
    return "No"
        


casenum = int(sys.stdin.readline())


testcases = []


for i in range(casenum):
    L, X = sys.stdin.readline().split()
    string = sys.stdin.readline()
    strlist = []
    for x in string:
        if x == 'i':
            strlist.append(2)
        if x == 'j':
            strlist.append(3)
        if x == 'k':
            strlist.append(4)
        
    testcases.append((int(L), int(X), strlist))

caseno = 1


for testcase in testcases:
    print "Case #"+str(caseno)+":", istrue(testcase[0], testcase[1], testcase[2])
    caseno += 1
