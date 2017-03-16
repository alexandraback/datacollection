'''
Created on Apr 12, 2014

@author: ononon1
'''


fname = "../Cookie2.txt"
f = open(fname, 'r')
fout = open(fname.replace(".txt","_out.txt"), 'w')
s = f.readline()
#print(s)
for i in range(1,(int(s)+1)):
    [C,F,X] = map(float,f.readline().split())
    print(C, F, X)
    n = 0
    T = C/2
    while(1):
        t1 = (X)/(2+(n+1)*F) #buy
        t2 = (X-C)/(2+n*F) #not buy

        if(t1<t2):
            n += 1
            T += C/(2+(n)*F)
        else:
            T += t2
            break
        #print(t1,t2,T)

    fout.write("Case #"+str(i)+": "+'{:.7f}'.format(T)+"\n")



