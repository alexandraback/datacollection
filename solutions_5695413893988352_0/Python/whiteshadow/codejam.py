__author__ = 'sushrutrathi'


def change(ent,fill):
    for i in fill:
        ent = ent.replace('?',i,1)
    return ent


with open('input.txt') as f:
    t = int(f.readline().split()[0])
    for k in range(1,t+1):
        c,j = f.readline().replace('\n','').split(' ')
        n = len(c)
        q = c.count('?')
        q1 = j.count('?')
        g = open('output.txt','a')
        if q==0 and q1==0:
            g.write('Case #' + str(k) + ': ' + c + ' ' + j + '\n')
            continue

        mn = 1000
        ans = [(j+c)]
        a= []
        b= []


        vals = 1
        for i in range(0, q):
            vals *= 10

        for i in range(0,vals):
            st = str(i).zfill(q)
            a.append(change(c,st))

        vals = 1
        for i in range(0, q):
            vals *= 10

        for i in range(0,vals):
            st = str(i).zfill(q1)
            b.append(change(j,st))

        for ii in a:
            for jj in b:
                kk = int(ii) - int(jj)
                if kk < 0:
                    kk = -kk

                if kk < mn:
                    mn = kk
                    del ans[:]
                    ans.append(jj+ii)
                elif kk == mn:
                    ans.append(jj+ii)




        ans = sorted(ans)

        g.write('Case #' + str(k) + ': ' + ans[0][n:] + ' ' + ans[0][0:n] + '\n')

