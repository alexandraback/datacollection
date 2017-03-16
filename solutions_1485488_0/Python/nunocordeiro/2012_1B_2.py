import sys

def initialize():
    file_in = 'D:\code jam\input.in'
    file_out = 'D:\code jam\output.txt'
    
    try:
        data_in  = open(file_in, 'r')
    except:
        print("Can't open file \'" + data_in +"\'")
        sys.exit()
    
    try:
        data_out  = open(file_out, 'w')
    except:
        print("Can't write to file \'" + data_out +"\'")
        sys.exit()

    return(data_in, data_out)

def get_variables():

    line = data_in.readline().split(' ')

    H=int(line[0]) 
    N=int(line[1])
    M=int(line[2])
    
    i=0
    C=[]
    while(i<N):
        j=0
        row=[]
        line = data_in.readline().split(' ')
        while(j<M):
            row.append( int(line[j]) )
            j+=1
        C.append( row )
        i+=1

    i=0
    F=[]
    while(i<N):
        j=0
        row=[]
        line = data_in.readline().split(' ')
        while(j<M):
            row.append( int(line[j]) )
            j+=1
        F.append( row )
        i+=1
       
#    print('C:', C)
#    print('F:', F)
#    print('b:', b)
#    print('p:', p)
#    print('points_list:', points_list)
    return(H,N,M,C,F)

def calculate_result(H,N,M,C,F):

    i=0
    memory=[]
    while(i<N):
        j=0
        row=[]
        while(j<M):
            row.append( 0 )
            j+=1
        memory.append( row )
        i+=1

    memory[0][0]=1
    
    i=0
    pos_time=[]
    while(i<N):
        j=0
        row=[]
        while(j<M):
            row.append( 9999999 )
            j+=1
        pos_time.append( row )
        i+=1

    #Calculate possible start positions
    pos_check_x=[]
    pos_check_x.append(0)
    pos_check_y=[]
    pos_check_y.append(0)


    #Calculate possible start positions
    while pos_check_x:
        pos_time[pos_check_x[0]][pos_check_y[0]]=0
        check_position(pos_check_x[0],pos_check_y[0],H,N,M,C,F,memory,pos_check_x,pos_check_y)
        del pos_check_x[0]
        del pos_check_y[0]
        
    #START WATER DOWN
    cur_time=0
    while(cur_time<pos_time[N-1][M-1]):
        i=0
        while(i<N):
            j=0
            while(j<M):
                if(cur_time == pos_time[i][j]):
                    #check how much time to reach surrounding
                    check_around(i,j,H-(10*cur_time),N,M,C,F,pos_time,cur_time)
                    
                j+=1
            i+=1
        #find smallest time after current and go
        next_time=9999999
        i=0
        while(i<N):
            j=0
            while(j<M):
                if(pos_time[i][j]>cur_time and pos_time[i][j]<next_time):
                    next_time=pos_time[i][j]         
                j+=1
            i+=1
        cur_time=next_time

        

    
    #print('pos_time:', pos_time)
    result=pos_time[N-1][M-1]
    return result

def check_around(x,y,W,N,M,C,F,pos_time,cur_time):
    if(W < F[x][y]+20):
        movement_speed=10
    else:
        movement_speed=1

    if(x>0 and pos_time[x-1][y] > (cur_time + movement_speed) ):
        check_this(x,y,x-1,y,W,N,M,C,F,pos_time,cur_time,movement_speed)   

    if(x+1<N and pos_time[x+1][y] > (cur_time + movement_speed) ):
        check_this(x,y,x+1,y,W,N,M,C,F,pos_time,cur_time,movement_speed)   

    if(y>0 and pos_time[x][y-1] > (cur_time + movement_speed) ):
        check_this(x,y,x,y-1,W,N,M,C,F,pos_time,cur_time,movement_speed)   

    if(y+1<M and pos_time[x][y+1] > (cur_time + movement_speed) ):
        check_this(x,y,x,y+1,W,N,M,C,F,pos_time,cur_time,movement_speed)
            
    return

def check_this(x1,y1,x2,y2,W,N,M,C,F,pos_time,cur_time,movement_speed):
    #Calculate how much time
    res=check_transition(x1,y1,x2,y2,0,C,F)
    if res:
        #check water and time
        if( W > C[x2][y2] - 50):
            #wait
            time_wait = -(C[x2][y2] - 50 - W)/10
            new_W=C[x2][y2] - 50

            if(new_W < F[x1][y1]+20):
                new_movement_speed=10
            else:
                new_movement_speed=1
            
            if( pos_time[x2][y2] > (cur_time + new_movement_speed + time_wait) ):
                pos_time[x2][y2]=cur_time + new_movement_speed + time_wait
        else:
            #move
            pos_time[x2][y2]=cur_time+movement_speed
    return;
        

def check_position(x,y,H,N,M,C,F,memory,pos_check_x,pos_check_y):
    if(x>0 and memory[x-1][y]==0):
        res=check_transition(x,y,x-1,y,H,C,F)
        if res:
            pos_check_x.append(x-1)
            pos_check_y.append(y)
            memory[x-1][y]=1
        
    if(x+1<N and memory[x+1][y]==0):
        res=check_transition(x,y,x+1,y,H,C,F)
        if res:
            pos_check_x.append(x+1)
            pos_check_y.append(y)
            memory[x+1][y]=1
        
    if(y>0 and memory[x][y-1]==0):
        res=check_transition(x,y,x,y-1,H,C,F)
        if res:
            pos_check_x.append(x)
            pos_check_y.append(y-1)
            memory[x][y-1]=1
         
    if(y+1<M and memory[x][y+1]==0):
        res=check_transition(x,y,x,y+1,H,C,F)
        if res:
            pos_check_x.append(x)
            pos_check_y.append(y+1)
            memory[x][y+1]=1
    return;

def check_transition(x1,y1,x2,y2,H,C,F):
    if( H > C[x2][y2] - 50):
        return 0
        
    if(F[x1][y1] > C[x2][y2] - 50):
        return 0
    
    if(C[x2][y2] < F[x2][y2] + 50):
        return 0
    
    if(C[x1][y1] < F[x2][y2] + 50):
        return 0
    
    return 1;
  
       
(data_in, data_out) = initialize()
no_test_cases = int( data_in.readline() )

i = 0
while ( i < no_test_cases ):
    i+=1
    H,N,M,C,F = get_variables()
    if(i==99):
        j=i
#        help('str')
    result = calculate_result(H,N,M,C,F)
    print( 'Case #' + str(i) + ': ' + str(result) )
    data_out.write( 'Case #' + str(i) + ': ' + str(result) + '\n' )
    


