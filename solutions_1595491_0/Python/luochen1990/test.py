import sys
sys.stdin = open('F:/Desktop/B-small-attempt0.in' , 'r')
sys.stdout = open('F:/Desktop/a.out' , 'w')

T = int(input())
for case in range(T) :
    line = input().split()
    N = int(line[0])
    S = int(line[1])
    p = int(line[2])
    p0 = p + max(0 , p - 1) * 2
    p1 = p + max(0 , p - 2) * 2
    t = []

    for i in range(N) :
        t.append(int(line[3 + i]))

    c0 = 0
    c1 = 0
    for x in t :
        if (x >= p0) :
            c0 += 1
        elif (x >= p1) :
            c1 += 1 
    
    #print (t)
    #print (c0 , c1 , S)
    r = c0 + min(c1 , S)     
    print ("Case #%d:"%(case + 1) , r)