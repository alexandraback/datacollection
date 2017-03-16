from collections import Counter

def main(case):
    
    print 'Case #{}:'.format(case),
    
    L = []
    
    for i in xrange(4):
        L.append(raw_input().strip())
    raw_input()

    def check(S):
        C = Counter(S)
        if C['O'] == 4 or C['O'] == 3 and C['T'] == 1:
            print 'O won'
            return True
        if C['X'] == 4 or C['X'] == 3 and C['T'] == 1:
            print 'X won'
            return True
        return False
            
    for i in xrange(4):
        if check(L[i]):
            return None
    
    for i in xrange(4):
        S = ''
        for j in xrange(4):
            S += L[j][i]
        if check(S):
            return None

    if check(L[0][0] + L[1][1] + L[2][2] + L[3][3]):
        return None
    if check(L[0][3] + L[1][2] + L[2][1] + L[3][0]):
        return None
    
    if all(not '.' in row for row in L):
        print 'Draw'
    else:
        print 'Game has not completed'


T = input()
for i in xrange(T):
    main(i + 1)
