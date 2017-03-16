#  --*-coding:utf-8-*--

def f(n):
    if (n == 0):
        return 'INSOMNIA'

    flags = [False]*10
    cnt = 0
    n2 = 0

    while(cnt < 10):
        n2 += n
        m = n2
        while(m > 0):
            if (not flags[m%10]):
                flags[m%10] = True
                cnt += 1

            m//= 10
        
        
    return n2


t = int(input())
for i in range(t):
    print('Case #' + str(i+1) + ':', f(int(input())))
    
