'''
Created on Apr 12, 2014

@author: ononon1
'''


fname = "../War3.txt"
f = open(fname, 'r')
fout = open(fname.replace(".txt","_out.txt"), 'w')
s = f.readline()
#print(s)
for i in range(1,(int(s)+1)):
    num = int(f.readline())
    Naomi = list(map(float,f.readline().split()))
    #print(Naomi)
    Ken = list(map(float,f.readline().split()))
    #print(Ken)
    all = sorted(Naomi + Ken)

    n=0
    w=0
    dw=0
    k=0
    for j in range(num*2):
        if(all[j] in Naomi):
            n=n+1
            if(k>0):
                dw=dw+1
                k=k-1
        else:
            k=k+1
            if(n>0):
                w=w+1
                n=n-1

    fout.write("Case #"+str(i)+": "+ str(dw) + " " + str(num-w)+"\n")




