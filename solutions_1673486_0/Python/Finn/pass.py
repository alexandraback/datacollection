fin = open('./A-small-attempt0.in','r')
fout = open('output','w')

N = int(fin.readline())

for i in range(1,N+1):

    [A,B] = map(int, fin.readline().split())

    p = map(float, fin.readline().split())

    if(A==1):
        keeptyping = p[0]*B+(1-p[0])*(2*B+1)
        backonce = B+2
        giveup = B+2
    else:
        pk = 1
        for pi in p:
            pk *= pi

        po = pk/p[A-1]
    
        keeptyping = pk*(B-A+1)+(1-pk)*(B-A+1+B+1)
        backonce = po*(B-A+3) +(1-po)*(2*B-A+3+1)
        giveup = B+2

    expect = min(keeptyping,backonce,giveup)

    ans = "Case #"+str(i)+": "+str(expect)+"\n"
    fout.write(ans)

fin.close()
fout.close()
    
    
