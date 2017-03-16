'''
Created on May 4, 2013

@author: johnny
'''


def foo(m, M):
    m = absorb(m,M)
    if not M:
        return 0
   
    tmp = M[:]
    #not double it
    r2 = len(M)
    
    #double it
    M = tmp[:] 
    if(2*m-1 > m):
        r1 = 1 + foo(2*m-1, M)
    else:
        r1 = r2
    M = tmp[:] 
    
    return min(r1,r2)
    
    
def absorb(m,M):
    if not M:
        return m
    while (M and m>M[0]):
        m += M[0]
        M.pop(0)
    return m
    
        
if __name__ == "__main3__":
    a = [1,2,3,40]
    b = 2;
    print absorb(b, a)
    print a

if __name__ == "__main__":
    input_path = 'inputB/A-large1.in'
    output_path = 'outputB/A-large1.out'
    
    input_file = open(input_path)
    
    result_list = []
    
    T = int(input_file.readline())

    for case_index in range(1,T+1):
        A, N = (int(s) for s in input_file.readline().split())
        M = list(int(s) for s in input_file.readline().split())
        print A,N
        print M
        M.sort()
        print M
        
        result = foo(A,M)
        
        result_str = 'Case #{0}:\t{1}'.format(case_index, result)
        result_list.append(result_str)
     
    input_file.close()   
    output_str = '\n'.join(result_list)
    print output_str
          
    output_file = open(output_path,'w+')
    output_file.write(output_str)
    output_file.close