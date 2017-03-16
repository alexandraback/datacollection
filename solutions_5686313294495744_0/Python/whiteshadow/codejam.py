__author__ = 'sushrutrathi'


def check(arr, fake):
    a=[]
    b=[]
    for i in arr:
        x,y = i.split(' ')
        a.append(x)
        b.append(y)

    for i in fake:
        x,y = i.split(' ')
        if (not x in a) or (not y in b):
            return False

    return True



with open('input.txt') as f:
    t = int(f.readline().split()[0])
    for k in range(1,t+1):
        n = int(f.readline().split()[0])
        arr = ['']*n
        ans = 0
        for i in range(0,n):
            arr[i] = f.readline().replace('\n','')

        formt = '{0:0%sb}' % str(n)
        n_pow = pow(2,n)
        for i in range(1,n_pow):
            val = formt.format(i)
            ls = []
            fake = []
            j = 0
            for v in val:
                if v=='1':
                    ls.append(arr[j])
                else:
                    fake.append(arr[j])
                j += 1


            if check(ls,fake):
                if val.count('0')>ans:
                    ans = val.count('0')








        g = open('output.txt','a')
        g.write('Case #' + str(k) + ': ' + str(ans) + '\n')