__author__ = 'fabrizio'

with open("input.txt") as fin:
    with open("output.txt","w") as fout:
        last=2**40
        T=int(fin.readline().strip())
        for t in range(1,T+1):
            P,Q=map(int,fin.readline().strip().split("/"))
            res=None

            for gen in range(1,41):
                anc=2**gen
                x_num=anc*P-Q #C
                x_den=Q*anc #D

                if x_num>=0 and (x_num*last)%x_den==0:
                    y=(x_num*last)/x_den
                    if y>=0 and y<=last-1:
                        res=gen
                        break
            fout.write("Case #"+str(t)+": "+("impossible" if res==None else str(res))+"\n")

