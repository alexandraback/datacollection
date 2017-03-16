from math import sqrt,ceil,floor

def is_fair(num):
    a = str(num)
    result = True
    l = len(a)
    for i in xrange(l/2):
        if a[i] != a[l-1-i]:
            result = False
            break
    return result

def solve(A,B):
    A1 = int(ceil(sqrt(A)))
    B1 = int(floor(sqrt(B)))
    print A1,B1
    fs = []
    for num in xrange(A1,B1+1):
        if is_fair(num):
            s = num**2
            if is_fair(s):
                fs.append(s)
    
    print fs
    return fs

def solve_cases(fin, fout):
    nCases = int(fin.readline().strip())
    As = []
    Bs = []
    for i in xrange(nCases):
        # get case
        A, B = map(int, fin.readline().strip().split())
        # solve case
        As.append(A)
        Bs.append(B)
    result = solve(min(As),max(Bs))
    l = len(result)
    for i in xrange(nCases):
        A = As[i]
        B = Bs[i]
        start = l
        for j in xrange(0, l):
            if result[j] >= A:
                start = j
                break
        end = l-1
        for j in xrange(start, l):
            if result[j] > B:
                end = j-1
                break
        print start, end
        r = 0
        if end - start + 1 > 0:
            r = end - start + 1
        fout.write("Case #%d: %s\n"%(i+1, r))
        print "Case #%d: %s\n"%(i+1, r)

from sys import argv
solve_cases(open(argv[1]), open(argv[1].replace("in", "out"), "w"))
