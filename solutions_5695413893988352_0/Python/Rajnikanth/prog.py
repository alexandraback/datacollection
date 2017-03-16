def hmd(x,y):
    l = 0
    for i in xrange(len(x)):
        if(x[i]=='?'):
            l+=1
        elif(x[i]==y[i]):
            l+=1
    return l
one = [str(i) for i in xrange(10)]
two = []
for i in one:
    two+=["0"+i]
for i in xrange(10,100):
    two+=[str(i)]
three = []
for i in two:
    three+=["0"+i]
for i in xrange(100,1000):
    three+=[str(i)]
t = input()
for T in xrange(1,t+1):
    print "Case #"+str(T)+":",
    inp = raw_input().split()
    x = inp[0]
    y = inp[1]
    l = len(x)
    lx = l
    ly = l
    ax = []
    ay = []
    if(l==1):
        for i in one:
            if(hmd(x,i)==lx):
                ax+=[i]
            if(hmd(y,i)==ly):
                ay+=[i]
        ans = (ax[0],ay[0],abs(int(ax[0])-int(ay[0])))
        for i in ax:
            for j in ay:
                diff = abs(int(i)-int(j))
                if(diff<ans[-1]):
                    ans = (i,j,diff)
                elif(diff==ans[-1]):
                    if(int(i)<int(ans[0])):
                        ans = (i,j,diff)
                    elif((int(i)==int(ans[0])) and (int(j)<int(ans[1]))):
                        ans = (i,j,diff)
    if(l==2):
        for i in two:
            if(hmd(x,i)==lx):
                ax+=[i]
            if(hmd(y,i)==ly):
                ay+=[i]
        ans = (ax[0],ay[0],abs(int(ax[0])-int(ay[0])))
        for i in ax:
            for j in ay:
                diff = abs(int(i)-int(j))
                if(diff<ans[-1]):
                    ans = (i,j,diff)
                elif(diff==ans[-1]):
                    if(int(i)<int(ans[0])):
                        ans = (i,j,diff)
                    elif((int(i)==int(ans[0])) and (int(j)<int(ans[1]))):
                        ans = (i,j,diff)
    if(l==3):
        for i in three:
            if(hmd(x,i)==lx):
                ax+=[i]
            if(hmd(y,i)==ly):
                ay+=[i]
        ans = (ax[0],ay[0],abs(int(ax[0])-int(ay[0])))
        for i in ax:
            for j in ay:
                diff = abs(int(i)-int(j))
                if(diff<ans[-1]):
                    ans = (i,j,diff)
                elif(diff==ans[-1]):
                    if(int(i)<int(ans[0])):
                        ans = (i,j,diff)
                    elif((int(i)==int(ans[0])) and (int(j)<int(ans[1]))):
                        ans = (i,j,diff)
    print ans[0],ans[1]

