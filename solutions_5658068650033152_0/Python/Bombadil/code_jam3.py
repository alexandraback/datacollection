#! /usr/bin/python -tt
# -*- coding: utf-8 -*-



fichier = open('workfile','r')
fout = open('file_out','w')

num_test = int((fichier.readline()).strip())
# caillou_N = f.readline().split()
# caillou_N = [float(i) for i in caillou_N]
# caillou_N.sort()

def pl(a,b):
    (a[0]+b[0],a[1]+b[1])


def f(N,M,K):
    minimum = K
    for n in range(2,min(K,N)+1):
        l = [0 for q in range(0,n)]
        for x in range(1, min(K,M)):
            l[0] = x
            for k in range(0,5**(n-1)):
                ktemp = k
                i = 1
                while i < n and l[i-1] < min(K,M)+1 and l[i-1] > 0:
                    l[i] = l[i-1] + (ktemp%5-2)
                    ktemp = (ktemp-ktemp%5)/5
                    i += 1
                if i == n and l[i-1] < min(K,M)+1 and l[i-1] >= 0:
                    per = l[0] + l[n-1] + 2*(n - 2)
                    if(sum(l) >= K and per < minimum): 
                        print sum(l)
                        minimum = per
                        print l
            
    return minimum



    

for num in range(0,num_test):

    [N,M,K] = [int(x) for x in (fichier.readline()).split()]
    value = f(N,M,K)

    print value
    fout.write("Case #"+ str(num+1) +": "+ str(value)+"\n")


    

    
    
