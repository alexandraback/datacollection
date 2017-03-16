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

def first(l):
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

    return I


def s(l, make):
    a = first(l)
    #table = [[[0 for i in xrange(len(a))] for j in xrange(len(a))] for k in xrange(len(a))]
    table = [0 for i in xrange(len(l))]


    counters = []

    for i in xrange(len(a)):
        if a[i] == make:
            table[i] = 1
            counters.append(i)

    return counters

def sol(l):
    I = s(l, 'i')
    for i in I:
        newL = l[i+1:]

        a = first(newL)
        b = [0 for i in xrange(len(newL))]
        counterJ = []

        for i in xrange(len(a)):
            if a[i] == 'j':
                b[i] = 1
                counterJ.append(i)

                for j in counterJ:
                    K = newL[j+1:]
                    if evaluate(K) == 'k':
                        return 'YES'

    return 'NO'



def solve(l):
    a = evaluate(l)
    s = set()
    #print a

    if a != '-1':
        return 'NO'
    
    for i in l:
        s.add(i)

    if len(s) == 1:
        return 'NO'

    return sol(l)

    
T = int(sys.stdin.readline())
for case in xrange(T):
    a = sys.stdin.readline().strip().split(' ')
    L, X = int(a[0]), int(a[1])
    l = sys.stdin.readline().strip().split(' ')

    string = l[0]*X
    #print string

    print 'Case #%d: %s' % (case + 1, solve(string))
    
