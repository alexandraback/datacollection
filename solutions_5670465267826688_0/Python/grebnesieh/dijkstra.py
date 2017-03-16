mul = {('j', '1'): 'j', ('k', 'i'): 'j', ('1', 'j'): 'j', ('1', '1'): '1', ('k', 'j'): 'i', ('1', 'k'): 'k', ('k', 'k'): '1', ('j', 'i'): 'k', ('k', '1'): 'k', ('i', 'j'): 'k', ('1', 'i'): 'i', ('j', 'k'): 'i', ('i', 'k'): 'j', ('i', 'i'): '1', ('i', '1'): 'i', ('j', 'j'): '1'}
neg = {('j', '1'): False, ('k', 'i'): False, ('1', 'j'): False, ('1', '1'): False, ('k', 'j'): True, ('1', 'k'): False, ('k', 'k'): True, ('j', 'i'): True, ('k', '1'): False, ('i', 'j'): False, ('1', 'i'): False, ('j', 'k'): False, ('i', 'k'): True, ('i', 'i'): True, ('i', '1'): False, ('j', 'j'): True}

def mult(x, y):
    return [mul[(x[0], y[0])], neg[(x[0], y[0])] ^ x[1] ^ y[1]]

def poww(x, n):
    if n == 0:
        return ['1', False]
    if x[0] == '1':
        if x[1]:
            if n % 2 == 0:
                return ['1', False]
            else:
                return ['1', True]
        return ['1', False]
    else:
        md = n % 4
        if md == 0:
            x[1] = False
            return ['1', False ^ x[1]]
        elif md == 1:
            return [x[0], False ^ x[1]]
        elif md == 2:
            x[1] = False
            return ['1', True ^ x[1]]
        elif md == 3:
            return [x[0], True ^ x[1]]

for c in xrange(input()):
    L, X = map(int, raw_input().split())
    S = raw_input()
    cS = [[S[0], False]]
    for i in xrange(1, L):
        cS.append(mult(cS[-1], [S[i], False]))
    last = poww(cS[-1], X)
    if last != ['1', True]:
        ans = "NO"
    else:
        mini, minj = -1, -1
        for i in xrange(min(4, X)):
            powi = poww(cS[-1], i)
            for j in xrange(L):
                gett = mult(powi, cS[j])
                if gett == ['i', False] and mini == -1:
                    mini = [i, j]
                if gett == ['k', False] and minj == -1 and mini != -1:
                    minj = [i, j]
        if mini == -1:
            ans = "NO"
        else:
            if minj == -1:
                for i in xrange(min(4, X - 4)):
                    powi = poww(cS[-1], i)
                    for j in xrange(L):
                        gett = mult(powi, cS[j])
                        if gett == ['k', False] and minj == -1:
                            minj = [i, j]
                if minj == -1:
                    ans = "NO"
                else:
                    ans = "YES"
            else:
                ans = "YES"                
    print "Case #" + str(c + 1) + ": " + ans
