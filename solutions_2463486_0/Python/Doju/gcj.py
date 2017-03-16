p=sorted(p) #p from gcj.cpp

t=input()

l = len(p)

for i in range(1, t+1):
        x, y  = raw_input().split()

        x = int(x)
        y = int(y)

        xc=yc=-1

        for j in range(0, l):
                if x <= p[j]:
                        xc = j
                        break

        for j in range(0, l)[::-1]:
                if y >= p[j]:
                        yc = j
                        break

        print "Case #%d: %d"%(i, yc-xc+1)
