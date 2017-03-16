infile = open('/home/suguman/Desktop/B-large(2).in', 'r')
outfile = open('/home/suguman/Desktop/output2.txt', 'w')
 
num = int(infile.readline())
i = 0
while i <num:
    l1 = ((infile.readline().strip()).split())
    n, m = int(l1[0]), int(l1[1])
    lawn = []
    j = 0
    while j < n:
        l3 = infile.readline().strip().split()
        l2 = [int(l3[i]) for i in range(m)]
        lawn = lawn + [l2]
        j += 1
    mylawn = [[max(lawn[j]) for i in range(m)] for j in range(n)]
    j = 0
    while j < m:   
        mymax = 0
        k = 0
        while k < n:
            if lawn[k][j] > mymax: 
                mymax = lawn[k][j]
            k += 1
        
        k = 0
        while k < n:
            if mylawn[k][j] >= mymax:
                mylawn[k][j] = mymax
            k += 1
        
        j += 1
    if (lawn == mylawn):
        ans = 'YES'
    else:
        ans = 'NO'
        
    outfile.write('Case #'+str(i+1)+': ' + ans+'\n')

    i += 1

        

    
        
    
    
