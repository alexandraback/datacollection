fin = open('./A-large.in','r')
fout = open('output','w')

N = int(fin.readline())

for i in range(1,N+1):

    [A,B] = map(int, fin.readline().split())

    p = map(float, fin.readline().split())

    back = B+2
    if(A==1):
        keeptyping = p[0]*B+(1-p[0])*(2*B+1)
        back = B+2
        giveup = B+2
    else:
        pk = 1
        for j in range(0,A):
            pk *= p[j]
            backj = pk*(A+B+1-2*j)+(1-pk)*(A+B+1-2*j+B+1)
            back = min(backj,back)
    
        keeptyping = pk*(B-A+1)+(1-pk)*(B-A+1+B+1)
        giveup = B+2

    expect = min(keeptyping,back,giveup)

    ans = "Case #"+str(i)+": "+str(expect)+"\n"
    fout.write(ans)

fin.close()
fout.close()
    
    
