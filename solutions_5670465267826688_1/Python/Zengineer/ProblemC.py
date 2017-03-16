import math
data_in = open("C-large.in", "r")
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
    if l == 1 or (l==2 and case[0]==case[1]):
        data_out.write("NO\n")
        continue
    
    for i in xrange(2, int(math.sqrt(l))):
        if l%i == 0:
            sub = case[:i]
            subf = True
            for j in xrange(1, l/i):
                sub2 = case[j*i:j*i+i]
                if sub != sub2:
                    subf = False
                    break
            if subf:
                case = sub
                X *= l/i
                l = i
                break
    
    test = (1,'1')
    for i in xrange(l):
        absq = q[(test[1],case[i])]
        test = (test[0]*absq[0], absq[1])
    if test == (1,'1') or (test == (-1,'1') and X%2 != 1):
        data_out.write("NO\n")
        print t+1, "Case 1"
        print test, X
        continue
    else:
        if test != (-1,'1') and X%4 != 2:
            data_out.write("NO\n")
            print t+1, "Case 2"
            print test, X
            continue
    """
    if X > 12:
        if X % 2 == 0:
            X = 12
        else:
            X = 13
    """
    L = l
    l *= X
    
    i = -1
    first = (1,'1')
    while i < l-2 and first != (1,'i'):
        i += 1
        absq = q[(first[1],case[i%L])]
        first = (first[0]*absq[0], absq[1])

    if first == (1,'i'):
        c = -1
        k = l
        third = (1,'1')
        while k > i+1 and third != (1,'k'):
            k -= 1
            absq = q[(case[k%L],third[1])]
            third = (third[0]*absq[0], absq[1])
        if third == (1,'k'):
            second = (1,'1')
            n = (k-i-1)/(4*L)
            i += 4*n*L
            while i < k-1:
                i += 1
                absq = q[(second[1],case[i%L])]
                second = (second[0]*absq[0], absq[1])
            if second == (1,'j'):
                data_out.write("YES\n")
                #print (t+1, case[:i+1], case[k:])
                continue
    data_out.write("NO\n")
    print t+1, "Case 3"
            
data_in.close()
data_out.close()
