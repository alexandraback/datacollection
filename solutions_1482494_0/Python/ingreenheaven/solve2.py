import sys

args = sys.argv

if len(args) < 2:
    print 'small or large?'
    exit()

inp = args[1]

out = open(inp + '_OUT', 'w')

# No change before this

T = input()

def copy(data, L, l):
    copy = []
    if l > 0:
        copy.extend(data[:l])
    if l < L-1:
        copy.extend(data[l+1:])
    return copy

def solve(data, stars):
    if data == None or data == []:
        return 0
    L = len(data)
    if L == 0:
        return 0

    best = -1
    for l in xrange(L):
        if data[l][0] == -1:
            if data[l][1] <= stars:
                return 1 + solve(copy(data, L, l), stars + 1)
        else:
            if data[l][1] <= stars:
                return 1 + solve(copy(data, L, l), stars + 2)
            elif data[l][0] <= stars:
                if best == -1 or data[best][1] < data[l][1]:
                    best = l
    if best == -1:
        return -1
    else:
        cp = []
        cp.extend(data)
        cp[best][0] = -1
        return 1 + solve(cp, stars + 1)

for i in xrange(1, T+1):
    N = input()
    data = []
    for j in xrange(N):
        data.append(map(int, raw_input().split()))

    ans = solve(data, 0)
    if ans == -1:
        res = 'Case #' + str(i) + ': Too Bad'
    else:
        res = 'Case #' + str(i) + ': ' + str(ans)
    print res
    out.write(res + '\n')

# No change after this

out.close()
