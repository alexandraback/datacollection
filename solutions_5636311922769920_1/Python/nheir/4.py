from math import ceil

if __name__ == '__main__':
    T = int(input())
    for nb in range(T):
        k,c,s = map(int,input().split())
        if k == 1:
            l = [1]
        elif k / c > s:
            l = None
        else:
            r = ceil(k/c)
            l = [0]*r
            for i in range(k):
                l[i//c] = l[i//c]*k+i
            l = [ i+1 for i in l ]
            for i in l:
                if i > k**c:
                    raise
        if l:
            print('Case #%d:' % (nb+1), ' '.join(map(str,l)))
        else:
            print('Case #%d:' % (nb+1), 'IMPOSSIBLE')