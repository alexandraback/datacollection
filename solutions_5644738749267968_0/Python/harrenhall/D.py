#!/usr/bin/python

cases = input()
for case in range(1, cases+1):
    
    print ("Case #" + str(case) + ":"),
    
    n=input()
    	
    naomi = raw_input().split()
    ken = raw_input().split()
    for i in range(n):
        naomi[i] = float(naomi[i])
        ken[i] = float(ken[i])
    
    naomi.sort()
    ken.sort()
    #print repr(naomi)
    #print repr(ken)
    naomit = naomi[:]
    kent = ken[:]
	
    war=0
    dec=0
    
    for i in range(n):
        na = naomi[0]
        del naomi[0]
        ke = 0
        for kev in ken:
            if kev>na:
                ke=kev
                del ken[ken.index(kev)]
                break
        if ke==0:
            del ken[0]
            war+=1
            
    naomi = naomit
    ken = kent
    
    for i in range(n):
        lasti = len(naomi)-1
        if naomi[0] > ken[0]:
            dec+=1
            #print dec,naomi[lasti],ken[0]
            del naomi[0]
            del ken[0]
        else:
            #print dec,naomi[0],ken[lasti]
            del naomi[0]
            del ken[lasti]
    
    
    
    
    print dec,war
