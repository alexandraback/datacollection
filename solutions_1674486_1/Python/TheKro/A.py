
def ans():
    N = int(raw_input())
    d = {}
    for n in range(1, N+1):
        vals = map(int,raw_input().split())
        M, L = vals[0], vals[1:]
        d[n] = L
    for n in range(1, N+1):
        visited = [False]*(N+1)
        queue = [n]
        while queue:
            t = queue.pop()
            if visited[t]:
                return "Yes"
            visited[t] = True
            for e in d[t]:
                if e != t: # Check visited?
                    queue += [e]
    return "No"
        

if __name__=="__main__":
    T = int(raw_input())
    for t in range(1, T+1):
        print "Case #"+str(t)+": "+ans()
