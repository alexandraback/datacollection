import sys
fileName = 'C-large'
sys.stdin = open('F:/Desktop/' + fileName + '.in' , 'r')
sys.stdout = open('F:/Desktop/' + fileName + '.out' , 'w')

T = int(input()) 
for case in range(1 , 1 + T) :
    line = input().split()
    A , B = line[0] , line[1]
    a , b = int(line[0]) , int(line[1])
    l = len(A)
    
    #cnt = 0 
    st = set()
    for n in range(a , b) :
        N = str(n)
        for k in range(1 , l) :
            M = N[k :] + N[: k]
            m = int(M) 
            if(m > n and m <= b) :
                st.add((n , m))
                #print("###" , n , m)
                #cnt += 1
            
        
    print('Case #%d:'%case , len(st))