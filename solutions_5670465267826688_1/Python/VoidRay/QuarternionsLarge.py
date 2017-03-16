import sys

mult_table = {('1', '1') : '1',
              ('1', 'i') : 'i',
              ('1', 'j') : 'j',
              ('1', 'k') : 'k',
                            
              ('i', '1') : 'i',
              ('i', 'i') : '-1',
              ('i', 'j') : 'k',
              ('i', 'k') : '-j',

              ('j', '1') : 'j',
              ('j', 'i') : '-k',
              ('j', 'j') : '-1',
              ('j', 'k') : 'i',

              ('k', '1') : 'k',
              ('k', 'i') : 'j',
              ('k', 'j') : '-i',
              ('k', 'k') : '-1'}


def evaluate(l):
    s = l[0]
    for i in xrange(1, len(l)):
        #print s
        if len(s) == 1:
            s = mult_table[s, l[i]]

        else:
            neg = s[1]
            t = mult_table[neg, l[i]]

            if len(t) == 1:
                s = '-' + t

            else:
                s = t[1]
    return s


def solve(a, X):
    e = evaluate(a)
    if e != '-1':
        #return 'NO'
        if X != 1 and X % 2 == 1:
            return 'NO'

    if X > 10:
        X = (X%4) + 8

    #print 2    
    """
    if X > 10:
        q = X/4
        if 4*q == X:
            X = 12

        else:
            X = X - 4*(q-1)        

    """
    l = a*X

    if evaluate(l) != '-1':
        return 'NO'
    I = []
    I.append(l[0])
    s = I[0]
    for i in xrange(1,len(l)):
        if len(s) == 1:
            s = mult_table[s, l[i]]
        else:
            neg = s[1]
            t = mult_table[neg, l[i]]
            if len(t) == 1:
                s = '-' + t
            else:
                s = t[1]

        I.append(s)
    #print I

    #print 1

    for i in xrange(len(I)):
        if I[i] == 'i':
            for j in xrange(i+1, len(I)):
                if I[j] == 'k':
                    return 'YES'


    return 'NO'





    
T = int(sys.stdin.readline())
for case in xrange(T):
    a = sys.stdin.readline().strip().split(' ')
    L, X = int(a[0]), int(a[1])
    l = sys.stdin.readline().strip().split(' ')
    #print l

    print 'Case #%d: %s' % (case + 1, solve(l[0], X))
    
