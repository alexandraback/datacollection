import sys
input = file(sys.argv[1])
M = 10000001
ans = [1<<31]*M
ans[0] = 0

def rev(s):
    return int(str(s)[::-1])

for s in range(1000001):
    ans[s+1] = min(ans[s+1], ans[s]+1)
    ans[rev(s)] = min(ans[rev(s)], ans[s]+1)

def solve1(s):
    return ans[s]


for case in range(int(input.readline())):
    s = int(input.readline())
    print "Case #%d: %d" % (case+1, solve1(s))
