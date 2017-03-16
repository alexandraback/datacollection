'''
Created on May 12, 2013

@author: johnny
'''

def foo(mystr):
    pass

def substr(string):
    j=1
    a=list()
    while True:
        for i in range(len(string)-j+1):
            a.append(string[i:i+j])
        if j==len(string):
            break
        j+=1
        #string=string[1:]
    return a

def barbar(mystr, n):
    a_list = list(mystr)
    count = 0
    c=list('bcdfghjklmnpqrstvwxyz')
    for item in a_list:
        if item in c:
            count += 1
        else:
            count = 0
        if count >= n:
#             print mystr
            return True
    return False

def bar(mystr, n):
    sub_list = substr(mystr)
    count = 0
    for item in sub_list:
#         print item
        if barbar(item, n):
            count += 1
    return count


if __name__ == "__main3__":
    string ='quartz'
    print substr(string)

if __name__ == "__main__":

    input_path = 'inputC/a.in'
    output_path = 'outputC/a.out'
    
    input_file = open(input_path)
    result_list = []
    
    T = int(input_file.readline())
    for case_index in range(1,T+1):
        mystr, n = input_file.readline().split()
        n = int(n)
#         print mystr, n
        result = bar(mystr, n)
        
        result_str = 'Case #%s: %d' % (case_index, result)
        
        result_list.append(result_str)
#         
    input_file.close()   
    output_str = '\n'.join(result_list)
    print output_str
    output_file = open(output_path,'w+')
    output_file.write(output_str)
    output_file.close