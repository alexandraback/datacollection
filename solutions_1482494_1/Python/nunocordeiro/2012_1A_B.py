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

    N = int( data_in.readline() )

    a=[] 
    b=[] 

    i=0
    while(i<N):
        line = data_in.readline().split(' ')
        a.append( int(line[0]) ) 
        b.append( int(line[1]) ) 
        i+=1

       
#    print('a:', a)
#    print('b:', b)
#    print('p:', p)
#    print('points_list:', points_list)
    return(N,a,b)

def calculate_result(N,a,b):
    result=0  
    stars=0
    
    possible=[]
    
    while(stars<N*2):
        i=0        
        while(i<N):
            if(b[i]<=stars):
                b[i]=3000
                if(a[i]!=3000):
                    a[i]=3000
                    stars+=2
                else:
                    stars+=1    
                i=0;
                result+=1
                continue;
            i+=1
 
        i=0
        no_possible=0   
        while(i<N):           
            if(a[i]<=stars):
                possible.append(i)
                no_possible+=1
            i+=1

        if(no_possible>0):
            i=0
            maximum=b[possible[i]]
            max_index=possible[i]
            while(i<no_possible):
                if(b[possible[i]]>maximum):
                    max_index=possible[i]
                    maximum=b[possible[i]]
            
                i+=1
            
            a[max_index]=3000
            stars+=1
            result+=1
            del possible[:]
            continue
        elif(stars==N*2):
            return result
        else:
            return 'Too Bad'
        
    #print('pair_list:', pair_list)
    return result

   
(data_in, data_out) = initialize()
no_test_cases = int( data_in.readline() )

i = 0
while ( i < no_test_cases ):
    i+=1
    N,a,b = get_variables()
    if(i==99):
        j=i
#        help('str')
    result = calculate_result(N,a,b)
    print( 'Case #' + str(i) + ': ' + str(result) )
    data_out.write( 'Case #' + str(i) + ': ' + str(result) + '\n' )
    


