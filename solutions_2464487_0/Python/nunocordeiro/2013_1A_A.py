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

    r = int(line[0])
    t = int(line[1])

#    print('r:', r)
#    print('t:', t)
    return(r, t)

def calculate_result(r, t):
    result=0
    first_circle_paint=((r+1)**2)-(r**2)
    t-=first_circle_paint
    circles=0
    
    current=first_circle_paint
    while(t>=0):
        current+=4
        t-=current
        circles+=1
    
    return circles

   
(data_in, data_out) = initialize()
no_test_cases = int( data_in.readline() )

i = 0
while ( i < no_test_cases ):
    i+=1
    r, t = get_variables()
    if(i==99):
        j=i
#        help('str')
    result = calculate_result(r, t)
    print( 'Case #' + str(i) + ': ' + str(result) )
    data_out.write( 'Case #' + str(i) + ': ' + str(result) + '\n' )
    


