import sys

sys.stdin = open("C-large.in", "r")
sys.stdout = open ("out.txt", "w");

T = input()
n, j = map(int, raw_input().split())
bit = [0]*50
bit[0] = 1
bit[n-1] = 1
ans = [[0]*15 for _ in range(510)]
an = 0
isP = [1]*1000010
pr = [0]*1000010
pn = 0

def init():
    global pn
    isP[0] = isP[1] = 0
    for i in xrange(2,1000000):
        if isP[i]:
            pr[pn] = i
            pn += 1
            j = i*i
            while j <= 1000000:
                isP[j] = 0
                j += i

def findfact(x):
    #print x
    for i in xrange(pn):
        if x % pr[i] == 0:
            return pr[i]
        if pr[i]*pr[i] > x:
            break
    return -1


def judge():
    global an
    b = 2
    while b < 11:
        bs = 1
        num = 0
        for j in xrange(0, n):
            num += bs if bit[n-1-j] else 0
            bs *= b
        fact = findfact(num)
        if fact != -1:
            ans[an][b] = fact
        else:
            break
        b += 1
    if b >= 11:
        ans[an][1] = num
        an += 1
    
        
def dfs(idx):
    global an
    if an >= j:
        return
    if idx == n-1:
        judge()
        return
    bit[idx] = 0
    dfs(idx+1)
    bit[idx] = 1
    dfs(idx+1)
    bit[idx] = 0

init()
dfs(1)

print "Case #%d:" %(1)
for i in xrange(an):
    for j in xrange(1,10):
        sys.stdout.write(str(ans[i][j]) + " ")
    sys.stdout.write(str(ans[i][10]) + "\n")
