from __future__ import print_function

f = open('C:\\Users\\djspence\\Downloads\\C-large.in', 'r')

#f = open('C:\\Users\\djspence\\Downloads\\testing.in', 'r')

f2 = open('C:\\Users\\djspence\\Documents\\Miscellaniety\\codejam2016\\fashionsoln.txt', 'w')

tries = int(f.readline())

for i in range(0, tries):
    vals = f.readline().split()
    
    j = int(vals[0])
    p = int(vals[1])
    s = int(vals[2])
    k = int(vals[3])
    
    num = min(j*p*s, j*p*k)
    
    print(("Case #" + str(i + 1) + ": " + str(num)), file = f2)
    
    if num == j*p*s:
        for a1 in range(1, j + 1):
            for a2 in range(1, p + 1):
                for a3 in range(1, s + 1):
                    sval = (a1 + a2 + a3) % s
                    if sval == 0:
                        sval = s
                    print((str(a1) + " " + str(a2) + " " + str(sval)), file = f2)           
    else:
        for a1 in range(1, j + 1):
            for a2 in range(1, p + 1):
                for a3 in range(1, k + 1):
                    sval = (a1 + a2 + a3) % s
                    if sval == 0:
                        sval = s
                    print((str(a1) + " " + str(a2) + " " + str(sval)), file = f2)
                    
    #if num == j*k*k:
    #    for a1 in range(1, j + 1):
    #        for a2 in range(1, k + 1):
    #           for a3 in range(1, k + 1):
    #                print((str(a1) + " " + str(a2) + " " + str(a3) + "\n"), file = f2)
    
f2.close()