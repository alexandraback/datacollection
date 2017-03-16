def solve(A,B):    
    Q = [(0,0)]
    newA = []
    newB = []
    
    for i in range(len(A)):
        newQ = []
        while Q:
            a, b = Q.pop()
##            print(a,A[i],b,B[i])
            if A[i]=='?' and B[i]=='?':
                if a==b:
                    newQ.append((10*a,10*b))
                    newQ.append((10*a+1,10*b))
                    newQ.append((10*a, 10*b+1))
                elif a>b:
                    newQ.append((10*a, 10*b+9))
                else:
                    newQ.append((10*a+9, 10*b))
            elif A[i]=='?':
                d = int(B[i])
                b1 = b*10 + int(B[i])
                if a==b:
                    newQ.append((b1, b1))
                    if d>0: newQ.append((b1-1, b1))
                    if d<9: newQ.append((b1+1,b1))
                elif a>b:
                    newQ.append((10*a, b1))
                else:
                    newQ.append((10*a+9, b1))
            elif B[i]=='?':
                d = int(A[i])
                a1 = a*10 + int(A[i])
                if a==b:
                    newQ.append((a1, a1))
                    if d>0: newQ.append((a1, a1-1))
                    if d<9: newQ.append((a1, a1+1))
                elif a>b:
                    newQ.append((a1, 10*b + 9))
                else:
                    newQ.append((a1, 10*b))
            else:
                a1 = a*10 + int(A[i])
                b1 = b*10 + int(B[i])
                newQ.append((a1, b1))
        mindiff = abs(newQ[0][0] - newQ[0][1])
        for a,b in newQ:
            if abs(a-b) < mindiff:
                mindiff = abs(a-b)
        while newQ:
            a, b = newQ.pop()
            if abs(a-b) - mindiff <= 1:
                Q.append((a,b))
    mina, minb = Q[0]
    mindiff = abs(mina-minb)
    for a,b in Q:        
        if abs(a-b) < mindiff:
            mina, minb, mindiff = a, b, abs(a-b)
        elif abs(a-b) == mindiff:
            if a < mina:
                mina, minb = a, b
            elif a == mina and b < minb:
                minb = b
    
    return mina, minb            

##f = open('in.txt','r')                 
f = open('large.in','r')
fo = open('out.txt','w')

T = int(f.readline())

for t in range(1,T+1):
    C,J = f.readline().split()

##    print('{:s} and {:s}'.format(C,J))
    c, j = solve(C,J)
    c_str, j_str = str(c).zfill(len(C)), str(j).zfill(len(J))
##    print('{:s} {:s}'.format(c_str, j_str))
    fo.write('Case #{:d}: {:s} {:s} \n'.format(t,c_str, j_str))
fo.close()
    
            
            
            

    
    
    
