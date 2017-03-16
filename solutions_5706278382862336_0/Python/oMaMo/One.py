'''
Created on May 11, 2014

@author: ononon1
'''
fname = "../One2.txt"
f = open(fname, 'r')
fout = open(fname.replace(".txt","_out.txt"), 'w')
s = f.readline()
#print(s)
for i in range(1,(int(s)+1)):
    #print(s)
    [P,Q] = map(int,(f.readline().split("/")))
    cnt = 1
    ans = 0
    v = (1.0*P)/Q
    fi=0
    while(cnt <=40):
        v = (v)*(2)
        #print(v)
        if(v >= 1):
            v = v-1
            if(fi==0):
                fi = 1
                ans = cnt
        cnt = cnt + 1

    print(P,Q)
    if(v!=0): anss = "impossible"
    else: anss = str(ans)
    fout.write("Case #"+str(i)+": "+anss+"\n")