'''
Created on 30/04/2014

@author: David Llorens (daybit@gmail.com)
'''

fIn=open("B-small-attempt0.in")
#fIn=open("B-large.in")
#fIn=open("test-B.txt")

T=int(fIn.readline())
P=[]
for i in range(T):
    a,b,k = [int(x) for x in fIn.readline().strip().split()]   
    P.append((a,b,k))
  
case = 0
fRes = open("res.txt", "w")  
for a,b,k in P:
    case += 1
    """
    print(a,b,k)
    ba=('0'*50+bin(a)[2:])
    bb=('0'*50+bin(b)[2:])
    bk=('0'*50+bin(k)[2:])
    print(ba, bb, bk)
    """
    c=0
    for aa in range(a):
        for bb in range(b):
            if aa&bb<k:
                c+=1

    print("Case #{}: {}".format(case, c)) 
    fRes.write("Case #{}: {}\n".format(case, c))  
    
fRes.close()