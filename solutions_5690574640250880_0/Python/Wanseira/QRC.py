import math
import time
start_time = time.time()

f = open("A.txt",'r')
ntests = int(f.readline())

g = open("output.txt",'w')

for i in range(ntests):

    
    p = f.readline()
    q = p.split()



    R = int(q[0])
    C = int(q[1])
    M = int(q[2])
    t = R*C-M

    row = ['*']*C #bombs, to be cleared up
    sol = []
    fail = 0

    if t==1:
        for j in range(R):
            sol.append(row[0:C])
        sol[0][0] = 'c'

    #special cases occur if boxes too small
    elif R==1:
        
        for j in range(t):
            row[j] = '.' #be very careful over list brackets, my code seems rubbishly complicated

        row[0] = 'c'
        sol.append(row)


    elif C==1:

        for j in range(R):
            if j<t:
                sol.append(['.'])
            else:
                sol.append(row)
        sol[0] = ['c']



    elif R==2:
        if t%2!=0 or t<4:
            fail = 1
        else:
            h = int(t/2)
            for j in range(h):
                row[j] = '.'
            sol = [row[0:C],row[0:C]]
            sol[0][0]='c'

    elif C==2:
        if t%2!=0 or t<4:
            fail = 1
        else:
            h = t/2

            for j in range(R):
                if j<h:
                    sol.append(['.','.'])
                else:
                    sol.append(row[0:C])
            sol[0] = ['c','.']

    else: #main for both sides at least 3
        if t in [1,2,3,5,7]:
            fail = 1
        else:
            for j in range(R):
                sol.append(row[0:C]) #init
                
            sol[0][0]='c'
            sol[0][1]='.'
            sol[1][0]='.'
            sol[1][1]='.'

            if t<=2*(R+C-2):
                if t%2 == 0:
                    h = int((t-4)/2)
                    if h<=R-2:
                        for k in range(h):
                            sol[k+2]=['.','.']+['*']*(C-2)


                    else:
                        h -= R-2
                        for k in range(R-2):
                            sol[k+2]=['.','.']+['*']*(C-2)

                        for k in range(h):
                            sol[0][k+2]='.'
                            sol[1][k+2]='.'

                if t%2 == 1:
                    h = int((t-9)/2)
                    sol[0][2]='.'
                    sol[1][2]='.'
                    sol[2][2]='.'
                    sol[2][1]='.'
                    sol[2][0]='.'

                    
                    if h<=R-3:
                        for k in range(h):
                            sol[k+3]=['.','.']+['*']*(C-2)
                    else:
                        h -= R-3
                        for k in range(R-3):
                            sol[k+3]=['.','.']+['*']*(C-2)

                        for k in range(h):
                            sol[0][k+3]='.'
                            sol[1][k+3]='.'
                        
                


            else:
                sol[0] = ['.']*C
                sol[1] = ['.']*C
                sol[0][0]='c'
                for k in range(R-2):
                    sol[k+2]=['.','.']+['*']*(C-2)

                t -= 2*(R+C-2)
                k=2
                while t>0:

                    if t>=C-2:
                        sol[k] = ['.']*C
                        t -= C-2
                        k +=1
                    else:
                        sol[k] = ['.']*(t+2)+['*']*(C-t-2)
                        t = 0
                
            
        
        

    s= sol


    g.write("Case #{}:\n".format(i+1))
    if fail==1:
        g.write("Impossible\n")
    else:
        for j in range(R):
            row = ""
            for k in range(C):
                row += sol[j][k]
            g.write(row+"\n")
    
f.close()
g.close()

print (time.time() - start_time, "secs")
