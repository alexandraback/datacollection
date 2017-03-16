filename="A-large (1).in"
f1=open(filename)
number=int(f1.readline())
result_list=list()

def work(input_string):
    result=input_string[0]
    for i in range(1,len(input_string)):
        if input_string[i]<result[0]:
            result=result+input_string[i]
        else:
            result=input_string[i]+result
    return result

for i in range(number):
    info=f1.readline().strip()
    result_list.append(work(info)) 

f2=open("output.txt",'w+')
for i in range(len(result_list)):
        line="Case #"+str(i+1)+": "+str(result_list[i])+'\n'
        f2.write(line)
f2.close()
            
