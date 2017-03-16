import math
data_in = open("C:\Users\Hao\Desktop\CS\Codejam\input\C-small-attempt4.in", "r")
data_out = open("ProblemC.out", "w")

q = {}
for i in xrange(3):
    c = chr(105+i)
    q[('1',c)] = (1,c)
    q[(c,'1')] = (1,c)
    q[(c,c)] = (-1,'1')
q[('1','1')] = (1,'1')
q[('i','j')] = (1,'k')
q[('j','i')] = (-1,"k")
q[('i','k')] = (-1,"j")
q[('j','k')] = (1,'i')
q[('k','i')] = (1,'j')
q[('k','j')] = (-1,"i")

T = int(data_in.readline())
for t in xrange(T):
    data_out.write("Case #%d: "%(t+1))
    arg = data_in.readline().split()
    #L = int(arg[0])
    X = int(arg[1])
    case = data_in.readline()[:-1]

    l = len(case)
    if l == 1:
        data_out.write("NO\n")
        continue
    
    l *= X
    case *= X

    i = -1
    first = (1,'1')
    while i < l-2 and first != (1,'i'):
        i += 1
        absq = q[(first[1],case[i])]
        first = (first[0]*absq[0], absq[1])

    if first == (1,'i'):
        c = -1
        k = l
        third = (1,'1')
        while k > i+1 and third != (1,'k'):
            k -= 1
            absq = q[(case[k],third[1])]
            third = (third[0]*absq[0], absq[1])
        if third == (1,'k'):
            second = (1,'1')
            for j in xrange(i+1,k):
                absq = q[(second[1],case[j])]
                second = (second[0]*absq[0], absq[1])
            if second == (1,'j'):
                data_out.write("YES\n")
                print (t+1, case[:i+1], case[k:])
                continue
    data_out.write("NO\n")
            
data_in.close()
data_out.close()
