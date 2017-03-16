import re
from sys import stdin 
VOWELS = 'aeiou'
def n_value(s, N):
    ans = 0
    for i in range(len(s)):
        for j in range(i+1, len(s)):
            if (j-i) - sum(s[i:j].count(v) for v in VOWELS) >= N :
                ans += 1
    return ans

def tri(n):
    return ((n+1)*n)//2

def n_val_sub(i,j,l,N):
    #print(i, j, l, N)
    #gives a substring of consanants
    ans = i*(j - (i + N) + 1) # start outer end inner
    #print(ans)
    ans += (j - (i + N) + 1)*(l-j) #start in end out
    #print(ans)
    ans += i*(l-j)
    #print(ans)
    ans += tri((j-i + 1) - N)
    #print(ans)
    return ans


def n_val(s, N):
    consstr = re.compile('.*?([^aoeui]{' + str(N) + ',10000000' +  '})+.*?')
    startends = [m.span(1) for m in re.finditer(consstr, s)]
    if len(startends) == 0:
        return 0
    a = n_val_sub(startends[-1][0],startends[-1][1], len(s), N)
    for (i,(s, e)) in enumerate(startends[:-1]):
        a += n_val_sub(s,e,startends[i+1][0] + N - 1,N)
    return a
    
T = int(stdin.readline())
for t in range(1, T + 1):
    s, N = stdin.readline().split()
    N = int(N)
    print("Case #%d: %d" % (t, n_val(s, N)))
