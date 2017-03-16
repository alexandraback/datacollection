import sys

best = None

def worse(ll, weight):
    global best
    if best == None:
        return False
    for i in range(len(ll)):
        if weight[ll[i]] > weight[best[i]]:
            return True
        elif weight[ll[i]] < weight[best[i]]:
            return False
    return False

def dfs(st, currentL, currentV, edges, weight, n):
    global best
    #print st, currentL, currentV
    if len(currentV) == n:
        if not worse(currentV, weight):
            best = currentV
    elif worse(currentV, weight):
        return
    else:
        ava = [e for e in edges if e[0] == st or e[1] == st]
        ava = [e[0] if e[1] == st else e[1] for e in ava]
        ava = [ed for ed in ava if ed not in currentV]
        ava = sorted(ava, key=lambda a: weight[a])
        #print ava
        for ed in ava:
            dfs(ed, currentL + [ed], currentV + [ed], edges, weight, n)
        if len(currentL) > 1:
            dfs(currentL[-2], currentL[0:-1], currentV, edges, weight, n)

if __name__=='__main__':
    t = int(sys.stdin.readline())
    for i in range(t):
        best = None
        sys.stdout.write("Case #{}: ".format(i + 1))
        n, m = map(int, sys.stdin.readline().split())
        ans = ''
        rmarks = [(i, sys.stdin.readline()[0:5]) for i in range(1, n + 1)]
        edges = [map(int, sys.stdin.readline().split()) for i in range(m)]
        marks = sorted(rmarks, key=lambda (i, v): v)
        proirity = map(lambda (i, v): i, marks)
        weight = [0 for i in range(len(proirity) + 1)]
        for i in range(len(proirity)):
            weight[proirity[i]] = i
        dfs(proirity[0], [proirity[0]], [proirity[0]], edges, weight, n)
        #print best
        ans = ''.join([rmarks[i - 1][1] for i in best])
        sys.stdout.write("{}\n".format(ans))

