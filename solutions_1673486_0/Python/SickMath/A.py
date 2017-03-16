fin = open('A-Small.in', 'r')
fout = open('A-Small.out', 'w')

cases = int(fin.readline()[:-1])

for case in range(cases) :
    A, B = map(int, fin.readline()[:-1].split(' '))
    P = map(float, fin.readline()[:-1].split(' '))
    ### continue typing ###
    prod = reduce(lambda x,y : x*y, P)
    s1 = prod * (B-A+1) + (1-prod) * (B-A+1+B+1)
    ### hit backspace x times ###
    s2 = []
    for i in range(A) :
        prod = reduce(lambda x,y : x*y, P[:i]) if i > 0 else 1.
        s2.append(prod * (B-i+1+A-i) + (1-prod) * (B-i+1+B+1+A-i))
    ### press enter now ###
    s3 = 1 + B + 1
    res = min(float(s1),min(s2),float(s3))
    # print 'Case #' + str(case+1) + ': ' + str(res)
    fout.write('Case #' + str(case+1) + ': ' + str(res) + '\n')
    
fin.close()
fout.close()
