if __name__ == '__main__':
    T = int(input())
    for i in range(T):
        k,c,s = map(int,input().split())
        if k == 1:
            l = [1]
        elif k != s:
            raise
        else:
            l = list(range(1,k+1))
            
        print('Case #%d:' % (i+1), ' '.join(map(str,l)))