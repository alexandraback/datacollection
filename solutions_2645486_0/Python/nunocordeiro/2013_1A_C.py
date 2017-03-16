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

    E = int(line[0])
    R = int(line[1])
    N = int(line[2])
 
    line = data_in.readline().split(' ')   
    v=[]
    for i in range(N):
        v.append( int(line[i]) )

#    print('E:', E)
#    print('R:', R)
#    print('N:', N)
#    print('v:', v)
    return(E,R,N,v)

def calculate_result(E,R,N,v):

    E_recover=[]
    result=0
    E_available=[]
    for i in range(N):
        E_recover.append(0)
        E_available.append(E)
    
    maxim=max(v)
    while maxim>0 :
        index_maxim = v.index(maxim)
        v[index_maxim]=0
        
        if E_recover[index_maxim] == 0:
            result += maxim * E_available[index_maxim]#energy spent here
            E_available[index_maxim]=0
        elif E-E_recover[index_maxim] < E_available[index_maxim]:
            result += maxim * (E_available[index_maxim] - (E-E_recover[index_maxim]) )#energy spent here
            E_available[index_maxim]=0
            
        #energy available for activities before and after
        j=1
        while j * R < E :
            if index_maxim+j<N and E_available[index_maxim+j] > j*R :
                E_available[index_maxim+j] = j*R
                  
            if index_maxim-j>=0 and (E_recover[index_maxim-j] > j*R or E_recover[index_maxim-j]==0):
                E_recover[index_maxim-j] = j*R
        
            j+=1
        maxim=max(v)
    

    return result

   
(data_in, data_out) = initialize()
no_test_cases = int( data_in.readline() )

i = 0
while ( i < no_test_cases ):
    i+=1
    E,R,N,v = get_variables()
    if(i==99):
        j=i
#        help('str')
    result = calculate_result(E,R,N,v)
    print( 'Case #' + str(i) + ': ' + str(result) )
    data_out.write( 'Case #' + str(i) + ': ' + str(result) + '\n' )
    


