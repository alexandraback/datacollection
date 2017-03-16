def solve():
    N, M = map(int, raw_input().split())
    a = []
    for n in range(N):
        a.append(map(int, raw_input().split()))
    hr = [0]*N
    hc = [0]*M
    for n in range(N):
        for m in range(M):
            hr[n] = max(hr[n], a[n][m])
            hc[m] = max(hc[m], a[n][m])
    for n in range(N):
        for m in range(M):
            if a[n][m] != min(hr[n], hc[m]):
                return 'NO'
    return 'YES'

def main():
    T = int(raw_input())
    for t in range(T):
        print 'Case #%d: %s' % (t+1, solve())

if __name__ == '__main__':
    main()
    