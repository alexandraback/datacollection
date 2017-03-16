import sys
sys.stdin = open('F:/Desktop/A-small-attempt0.in' , 'r')
sys.stdout = open('F:/Desktop/a.out' , 'w')
A = 'ejp mysljylc kd kxveddknmc re jsicpdrysi rbcpc ypc rtcsra dkh wyfrepkym veddknkmkrkcd de kr kd eoya kw aej tysr re ujdr lkgc jv y e q'
B = 'our language is impossible to understand there are twenty six factorial possibilities so it is okay if you want to just give up a o z'
D = {A[i] : B[i] for i in range(len(A))}
D['z'] = 'q'
#for x in sorted([a for a in D]) :
#    print (x)
T = int(input())
for case in range(T) :
    l = sys.stdin.readline()
    if(l[-1] == '\n') :
        l = l[0 : -1]
    ll = ''
    for c in l :
        ll += D[c]
    print ('Case #%d:'%(case + 1) , ll)
    