import pprint
import codecs
import copy

def walkable(a, b):
    print "walkable: " + str(a) + " " + str(b)
    if len(C[a]) == 0 or a == b:
        return False
    elif b in C[a]:
        print "  yes"
        return True
    else:
        for l in C[a]:
            if walkable(l, b) == True:
                print "  yes"
                return True
    return False

def test(i, j):
    print "test: " + str(i) + " " + str(j)
    if len(C[i]) == 0:
        return False
    else:
        count = 0
        if j in C[i]:
            count += 1
        for k in C[i]:
            if walkable(k, j):
                count += 1
            if count > 1:
                return True
    return False
            
file = codecs.open("diamond_inh.small.in", encoding="utf-8", mode="r")
outfile = codecs.open("diamond_inh.small.out", encoding="utf-8", mode="w")
totalCases = int(file.readline())
for case in range(totalCases):
    N = int(file.readline())
    C = []
    for i in range(0, N):
        line = file.readline().rstrip('\n').split(' ')
        tmp = [int(x)-1 for x in line[1:]]
        C.append(tmp)
    print "Test Case #" + str(case+1)
    print C
    answer = False
    for i in range(0, N):
        for j in range(0, N):
            if i != j:
                answer = test(i, j)
                if answer == True:
                    break
        if answer == True:
            break
    if answer == True:
        print "Test Case #" + str(case+1) + ": Yes"
        outfile.write("Case #" + str(case+1) + ': Yes'+ '\n')
    else:
        print "Test Case #" + str(case+1) + ": No"
        outfile.write("Case #" + str(case+1) + ': No'+ '\n')
    
    
