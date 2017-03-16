def main():
    from collections import deque
    maxn = 10 ** 6
    remaind = maxn - 1
    d = [-1] * (maxn + 1)
    d[1] = 1
    used = set([1])
    q = deque([1])
    while remaind > 0:
        x = q.popleft()
        a = x + 1
        b = int(''.join(reversed(str(x))))
        if a not in used:
            used.add(a)
            q.append(a)
            d[a] = d[x] + 1
            if a <= maxn: remaind -= 1
        if b not in used:
            used.add(b)
            q.append(b)
            d[b] = d[x] + 1
            if b <= maxn: remaind -= 1
    
    with open("input.txt") as fin, open("output.txt", 'w') as fout:
        t = int(fin.readline())
        for i in range(t):
            n = int(fin.readline())
            print("Case #{0}: {1}".format(i + 1, d[n]), file=fout)
    
    
    
    
        
    
main()
