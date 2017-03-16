def matchPattern(x, p):
    if len(p) < len(str(x)):
        return False
    l = len(p)
    s = '0'*(l-len(str(x))) + str(x)
    for i in range(l):
        if(p[i] == '?' or p[i] == s[i]):
            pass
        else:
            return False
    return True
        

for cases in range(1, int(input()) + 1):
    C, J = input().split()
    md = 10000
    pair = None

    for i in range(1000)[::-1]:
        if(matchPattern(i, C)):
            for j in range(1000)[::-1]:
                if(matchPattern(j, J)):
                    if(abs(i-j) <= md):
                        md = abs(i-j)
                        pair = (i,j)
    l = len(C)
    s1 = '0'*(l-len(str(pair[0]))) + str(pair[0])
    s2 = '0'*(l-len(str(pair[1]))) + str(pair[1])
    pair = (s1,s2)
    print('Case #%d:' % (cases,), *pair)
