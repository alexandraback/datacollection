import sys

def prework(argv):
    '''do something according to argv,
    return a message describing what have been done.'''
    
    return "nothing"

def once():
    '''to cope once'''
    r, c, m = tuple(int(x) for x in input().split()) # 1<=r,c<=50, 0<=m<r*c
    
    re = False
    if r > c : 
        r, c = c, r
        re = True
    
    ans = None
    def mkrow(m) :
        return list('.'*(c-m) + '*'*m )
    e = r*c - m
    printerr('r=%d c=%d m=%d e=%d'%(r,c,m,e))
    if e == 1 :
        ans = [mkrow(c) for _ in range(r)]
    elif r == 1 :
        ans = [mkrow(m)]
        #ans[0][0] = 'c'
    elif r == 2 :
        if e>2 and e%2 == 0 :
            ans = [mkrow(m//2) for _ in range(2)]
            #ans[0][0] = 'c'
    else :
        if e >= 9 :
            ans = [mkrow(0) for _ in range(r)]
            for i in range(r-1, 2-1, -1) :
                mm = min(m, c-2)
                ans[i] = mkrow(mm)
                m -= mm
            if m > 0 :
                if m%2 > 0 :
                    ans[2][2] = '.'
                    m += 1
                for i in range(r-1, 3-1, -1) :
                    if m == 0 : break
                    ans[i][0] = ans[i][1] = '*'
                    m -= 2
                for j in range(c-1, 3-1, -1) :
                    if m == 0 : break
                    ans[0][j] = ans[1][j] = '*'
                    m -= 2
            #ans[0][0] = 'c'
        elif e in (4,6,8) :
            ans = [mkrow(c-2) for _ in range(2)] + [mkrow(c) for _ in range(r-2)]
            if e >= 6 : ans[0][2] = ans[1][2] = '.'
            if e >= 8 : ans[2][0] = ans[2][1] = '.'
            #ans[0][0] = 'c'
    if ans == None : return 'Impossible'
    if re : ans = [[ans[j][i] for j in range(r)] for i in range(c)]
    ans[0][0] = 'c'
    return '\n'.join(''.join(l) for l in ans)

def printerr(*v):
    print(*v, file=sys.stderr)

def main():
    TT = int(input())
    for tt in range(1,TT+1):
        printerr("coping Case %d.."%(tt))
        ans = once()
        print("Case #%d:\n%s"%(tt, (ans)))

if __name__ == '__main__' :
    msg = prework(sys.argv)
    print("prework down with", msg, file=sys.stderr)
    main()
