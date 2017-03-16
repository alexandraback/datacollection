def firstIndex(x, i) :
    for index, elem in enumerate(x) :
        if elem[1] == i :
            return index
    return -1

def totalSum(x) :
    res = {}
    for i in x :
        n, t = i
        res[t] = res.get(t,0) + n
    return res

def compTotalSum(a, b) :
    A = totalSum(a)
    B = totalSum(b)
    tot = 0
    for k in A :
        tot += min(A[k], B.get(k,0))
    return tot

def simplify(x) :
    res = [x[0]]
    for i in x[1:] :
        val, t = i
        if t == res[-1][1] :
            res[-1][0] += val
        else :
            res.append([val,t])
    return res

letter = 'C'
size = 'small'

fin = open(letter + '-' + size + '.in', 'r')
fout = open(letter + '-' + size + '.out', 'w')

cases = int(fin.readline()[:-1])

for case in range(cases) :
    N, M = map(int, fin.readline()[:-1].split(' '))
    A = map(int, fin.readline()[:-1].split(' '))
    B = map(int, fin.readline()[:-1].split(' '))
    A = [A[n:n+2] for n in range(0, len(A), 2)]
    B = [B[n:n+2] for n in range(0, len(B), 2)]
##    caseToCheck = 6
##    if case < caseToCheck :
##        continue
##    if case > caseToCheck :
##        break
##    print
##    print A
##    print B
    S = 0
    while True :
        # raw_input('PRESS ENTER TO CONTINUE!')
        A = filter(lambda x : x[1] in set([i[1] for i in B]), A)
        B = filter(lambda x : x[1] in set([i[1] for i in A]), B)
        if A == [] or B == [] :
            break
        A = simplify(A)
        B = simplify(B)
        Avalue, Atype = A[0]
        Bvalue, Btype = B[0]
        if Atype == Btype :
            if Avalue < Bvalue :
                B[0][0] -= Avalue
                A = A[1:]
                S += Avalue
            elif Avalue == Bvalue :
                A = A[1:]
                B = B[1:]
                S += Avalue
            else :
                A[0][0] -= Bvalue
                B = B[1:]
                S += Bvalue
        else :
            Aid = firstIndex(A, Btype)
            Bid = firstIndex(B, Atype)
            if Aid == -1 and Bid != -1 :
                B = B[Bid:]
            elif Aid != -1 and Bid == -1 :
                A = A[Aid:]
            elif Aid == -1 and Bid == -1 :
                break
            else :
                Amove = compTotalSum(A[Aid:],B)
                Bmove = compTotalSum(A,B[Bid:])
                if Amove > Bmove :
                    A = A[Aid:]
                else :
                    B = B[Bid:]
##        print
##        print A
##        print B
    res = S
    print 'Case #' + str(case+1) + ': ' + str(res)
    fout.write('Case #' + str(case+1) + ': ' + str(res) + '\n')
    
fin.close()
fout.close()
