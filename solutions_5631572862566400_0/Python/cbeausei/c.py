import sys
sys.setrecursionlimit(1000000000)

def test(l):
    global maxi
    if len(l) == 1:
        return
    if bff[l[0]] not in [l[1], l[len(l) - 1]]:
        return
    if bff[l[len(l) - 1]] not in [l[0], l[len(l) - 2]]:
        return
    """
    for i in range(1, len(l) - 1):
        if bff[l[i]] not in [l[i - 1], l[i + 1]]:
            return"""
    maxi = max(maxi, len(l))
    
def find(l):
    test(l)
    for i in range(n):
        if i not in l:
            if len(l) > 1 and bff[l[len(l) - 1]] not in [l[len(l) - 2], i]:
                continue
            l.append(i)
            find(l)
            l.pop()

T = int(input())
for N in range(1, T + 1):
    out = 'Case #' + str(N) + ': '
    n = int(input())
    bff = [int(i) - 1 for i in input().split()]
    maxi = 0
    for i in range(n):
        find([i])
    out += str(maxi)
    out += '\n'
    sys.stdout.write(out)
    sys.stdout.flush()
    sys.stderr.write(out)
    sys.stderr.flush()