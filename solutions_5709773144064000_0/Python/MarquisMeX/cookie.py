

if __name__ == '__main__':
    file_in=open('B-small-attempt0.in','r')
    file_out=open('output.out','w')
    loop = file_in.readline()
    
    for a in range(int(loop)):

        total_time=0

        rate=2.0
        
        C,F,X=map(float,file_in.readline().split(' '))

        buy=True
            
        
        while (buy==True):

            if (X/rate>=C/rate+X/(rate+F)):
                buy=True
                total_time+=C/rate
                rate+=F
            else:
                buy=False
                total_time+=X/rate

        #print total_time
        file_out.write ("Case #%d: %f\n"%(a+1,total_time))
        '''    
        if len(ans)==0:
            file_out.write("Case #%d: Volunteer cheated!"%(a+1))
        elif len(ans)>1:
            file_out.write("Case #%d: Bad magician!"%(a+1))
        else:
            file_out.write("Case #%d: %d"%(a+1,ans.pop()))

        if a!=int(loop)-1:
            file_out.write("\n")
        '''
    file_in.close()
    file_out.close()
    
