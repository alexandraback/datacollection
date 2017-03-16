from string import ascii_lowercase
import sys
import Queue

def getarray(N, M):
    a = []
    for i in range(N):
        b = []
        for j in range(M):
            b.append(0)
        a.append(b)
    return a

def check_diamond(istring):
    unique = ''.join(sorted(set(istring),key=istring.index))
    if unique == istring:
        return False
    else:
        return True

def dfs(cur, N, rarray, visited):
    print 'visiting', cur
    if visited[cur]:
        return True
    visited[cur] = 1
    for i in range(N):
        if rarray[cur][i]:
            val = dfs(i, N, rarray, visited)
            if val:
                return val
    return False

def process_rarray(N, rarray, bases):
    for i in bases:
        visited = [0] * N
        if dfs(i, N, rarray, visited):
            return True
    return False

def process(N, iarray):
    rarray = getarray(N, N)
    for i in range(N):
        for j in range(N):
            if iarray[i][j]:
                rarray[j][i] = 1
    bases = []
    for i in range(N):
        cur = i
        base = True
        for j in range(N):
            if rarray[j][cur] > 0:
                base = False
        if base:
            bases.append(cur)
    return process_rarray(N, rarray, bases) and 'Yes' or 'No'
    ivalues = [0] * N
    for i in range(N):
        ivalues[i] = str(i)
    queue = Queue.Queue()
    for i in bases:
        queue.put(i)
    while queue.empty() == False:
        cur = queue.get()
        value = ivalues[cur]
        if check_diamond(value):
            return 'Yes'
        for i in range(N):
            if rarray[cur][i] > 0:
                ivalues[i] += value
                queue.put(i)
    return 'No'
        
    

if __name__ == '__main__':
    fname = sys.argv[1]
    rf = open(fname + '.in', 'r')
    of = open(fname + '.out', 'w')
    tt = int(rf.readline())
    for case in range(tt):
        N = rf.readline().strip()
        N = int(N)
        inheritance_array = getarray(N,N)
        for i in range(N):
            val = rf.readline().strip()
            val = [int(v) for v in val.split(' ')]
            n = val[0]
            val = val[1:]
            for v in range(n):
                inheritance_array[i][val[v] - 1] = 1
        output = process(N, inheritance_array)
        print output
        of.write('Case #%d: %s\n' %  (case+1, output))
