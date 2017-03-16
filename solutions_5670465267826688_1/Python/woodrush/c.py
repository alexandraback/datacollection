import sys

q = {}
q['1'] = 0
q['i'] = 1
q['j'] = 2
q['k'] = 3
q['-1'] = 4
q['-i'] = 5
q['-j'] = 6
q['-k'] = 7

qinv = {}
qinv[q['1']]  = q['1']
qinv[q['i']]  = q['-i']
qinv[q['j']]  = q['-j']
qinv[q['k']]  = q['-k']
qinv[q['-1']] = q['-1']
qinv[q['-i']] = q['i']
qinv[q['-j']] = q['j']
qinv[q['-k']] = q['k']

qprod = [
    [q['1'], q['i'], q['j'], q['k'],     q['-1'],q['-i'],q['-j'],q['-k']],
    [q['i'], q['-1'],q['k'], q['-j'],    q['-i'],q['1'], q['-k'],q['j']],
    [q['j'], q['-k'],q['-1'],q['i'],     q['-j'],q['k'], q['1'], q['-i']],
    [q['k'], q['j'], q['-i'],q['-1'],    q['-k'],q['-j'],q['i'], q['1']],
    [q['-1'],q['-i'],q['-j'],q['-k'],    q['1'], q['i'], q['j'], q['k']],
    [q['-i'],q['1'], q['-k'],q['j'],     q['i'], q['-1'],q['k'], q['-j']],
    [q['-j'],q['k'], q['1'], q['-i'],    q['j'], q['-k'],q['-1'],q['i']],
    [q['-k'],q['-j'],q['i'], q['1'],     q['k'], q['j'], q['-i'],q['-1']]
]

def qpown(q,n):
    ret = 0
    for i in range(0,n%4):
        ret = qprod[ret][q]
    return ret

def check(t,L,X,string):
    pieceval = 0
    leftvals = [0 for i in range(len(string)+1)]
    rightvals = [0 for i in range(len(string)+1)]
    for i in range(0,len(string)):
        pieceval = qprod[pieceval][q[string[i]]]
        leftvals[i+1] = pieceval

    if qpown(pieceval,X%4) != qprod[q['i']][qprod[q['j']][q['k']]]:
        print "Case #%d: NO" % (t+1)
        return

    for i in range(len(leftvals)):
        rightvals[i] = qprod[qinv[leftvals[i]]][pieceval]

    for leftind in range(len(leftvals)):
        # for nl in range(0,min(4,X-1+1)):
        for nl in range(0,4):
            if qprod[qpown(pieceval,nl)][leftvals[leftind]] == q['i']:
                for rightind in range(len(rightvals)):
                    # for nr in range(0,min(4,X-1-nl+1)):
                    for nr in range(0,4):
                        if qprod[rightvals[rightind]][qpown(pieceval,nr)] == q['k']:
                            if ((nl + nr == X - 1) and (leftind < rightind)) or (nl + nr < X - 1):
                                if qprod[q['-i']][qprod[qpown(pieceval,X%4)][q['-k']]] == q['j']:
                                    print "Case #%d: YES" % (t+1)
                                    return
    print "Case #%d: NO" % (t+1)

if __name__ == "__main__":
    T = int(sys.stdin.readline())
    for t in range(0,T):
        string = sys.stdin.readline().split(' ')
        L = int(string[0])
        X = int(string[1].rstrip())
        string = sys.stdin.readline().rstrip()
        #======================================
        check(t,L,X,string)





