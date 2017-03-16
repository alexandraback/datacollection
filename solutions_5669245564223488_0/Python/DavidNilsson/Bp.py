from collections import deque
from itertools import permutations
f = open('./B-small-attempt2.in')
f# = open('./test.in')
nbrs = deque([k for k in f.read().split()])
f.close()

def hasnext():
    return len(nbrs) > 0

def read():
    return nbrs.popleft()


mod = 1000000007
dp = dict()
def backtrack(ws, ff, ll, letters, last, used):
    ans = 0
    
    if False not in used:
        return 1
    
    for k in range(len(used)):
        if not used[k]:
            ok = True
            for i in ws[k]:
                if i in letters and i != last:
                    ok = False
                    break
                if i in letters and i != ff[k]:
                    ok = False
            if ok:
                L = set(letters)
                L = L.union(ws[k])
                u = [i for i in used]
                u[k] = True
                ans += backtrack(ws, ff, ll, L, ll[k], tuple(u))
    return ans

f = open('out.txt', 'w')
cases = int(read())
for cc in range(1, cases+1):
    N = int(read())
    words = []
    wordsets = []
    last = []
    first = []
    for k in range(N):
        words.append(read())
        wordsets.append(set([i for i in words[k]]))
        last.append(words[k][-1])
        first.append(words[k][0])

    ans = backtrack(wordsets, first, last, set([]), '0', tuple([False for k in range(N)]))
    
    print(cc)
    f.write("Case #" + str(cc) + ": " + str(ans) + "\n")
    
f.close()

f = open('out.txt')
for line in f:
    print(line.strip())
f.close()