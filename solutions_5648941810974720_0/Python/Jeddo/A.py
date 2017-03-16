def rem(S,letter,word):
    count = 0
    while S.__contains__(letter):
        count +=1
        for i in word:
            S.remove(i)
    return count
def decode(S):
    res = []
    res += [0]*rem(S,'Z','ZERO')
    res += [2]*rem(S,'W','TWO')
    res += [4]*rem(S,'U','FOUR')
    res += [6]*rem(S,'X','SIX')
    res += [7]*rem(S,'S','SEVEN')
    res += [8]*rem(S,'G','EIGHT')
    res += [1]*rem(S,'O','ONE')
    res += [3]*rem(S,'H','THREE')
    res += [5]*rem(S,'F','FIVE')
    res += [9]*rem(S,'N','NINE')
    res.sort()
    res = map(str,res)
    res = ''.join(res)
    return res

inf = open('A-small.in','r')
out = open('A-small.out','w')

T = int(inf.readline())
for i in range(1,T+1):
    S = map(str,inf.readline())
    res = decode(S)
    out.write('Case #%d: %s \n' %(i,str(res)))
out.close()
inf.close()
