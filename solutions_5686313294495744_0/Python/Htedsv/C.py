import sys
import math

words = []
inset = []
n = 0
def satisfy():
    assert len(words) == len(inset)
    firsts, seconds, total = set([]), set([]), set([])
    for i in range(n):
        if inset[i] == True:
            firsts.add(words[i][0])
            seconds.add(words[i][1])
            total.add(tuple(words[i]))
    for i in range(n):
        if inset[i] == False:
            if words[i][0] not in firsts or words[i][1] not in seconds or tuple(words[i]) in total:
                return False
    return True


def check(pos):
    if pos == n:
        if satisfy():
            return inset.count(False)
        else:
            return 0
    else:
        ans = check(pos + 1)
        inset[pos] = True
        ans = max(ans, check(pos + 1))
        inset[pos] = False
        return ans

            
f = open(sys.argv[1])
T = int(f.readline())
for I in range(T):
    n = int(f.readline())
    words = []
    inset = [False] * n
    for i in range(n):
        words.append(f.readline()[:-1].split(' '))
    ans = check(0)
    print 'Case #%d: %d'%(I+1, ans)

