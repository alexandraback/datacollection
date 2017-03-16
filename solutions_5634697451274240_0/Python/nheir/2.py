if __name__ == '__main__':
    T = int(input())
    for i in range(T):
        p = reversed(input())
        t = '+'
        n = 0
        for c in p:
            if t != c:
                t = c
                n+=1
        print('Case #%d: %d' % (i+1,n))