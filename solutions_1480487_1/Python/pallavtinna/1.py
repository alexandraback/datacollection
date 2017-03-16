#/usr/bin/python

def main():
    test = int(raw_input())
    for i in range(test):
        mult=1
        s = raw_input()
        l = map(int,s.split())
        n = l[0]
        flag=0
        l.remove(l[0])
        x = sum(l)
        a =[]
        print 'Case #%d:' %(i+1),

        for j in l:
            y = x - j
            z = (n-1)*j
            t = float(z-y)/x
            a.append(((1.0-t)/n)*100)
        neg=0
        sn=0.0
        flag=0
        for jj in a:
            if jj<0:
                flag=1
                neg = neg + 1
                sn = sn + jj
        if flag==1:
            for jj in a:
                if jj<0:
                    print "0.00000",
                else:
                    print jj+(sn/float(n - neg)),
        else:
            for jj in a:
                print jj,
        print
            
            
if __name__ == "__main__":
        main()

