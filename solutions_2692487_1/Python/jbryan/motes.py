from math import *

#input_file = open('../test_input.txt','r')
input_file = open('A-large.in','r')
raw_input = input_file.read()
input_file.close()

lines = raw_input.split('\n')

num_cases = int(lines[0])
case_num = 1

output_text = ''
output_file = open('osmos_output.txt','w')

case_start_line = 1

while case_num<=num_cases:
    A,N = (int(z) for z in lines[case_start_line].split(' '))
    motes = list(int(z) for z in lines[case_start_line+1].split(' '))

    motes.sort()
    new_motes_needed = [0]*N
    
    #print('A,N: ',A,N)
    #print('Motes: ',motes)

    running_total=A
    ops = 0
    i=0
    if A==1:
        ops=N
    else:
        while i<N:
            if motes[i]<running_total:
                running_total+=motes[i]
                i+=1
            else:
                ops+=1
                running_total += running_total-1  #new mote when necessary, of max size possible
                new_motes_needed[i]+=1

    #print('New motes needed, ops: ',new_motes_needed,ops)

    #loop backwards to beginning from second to last
    for i in reversed(range(N-1)):
        new_motes_needed[i]+=new_motes_needed[i+1]

    #print('New motes needed: ',new_motes_needed)

    max_gain=0
    for i in range(N):
        if new_motes_needed[i]-(N-i) > max_gain: #if we added more needed than the number of motes needed
            max_gain = new_motes_needed[i]-(N-i)

    ops-=max_gain
    #print('max gain,ops: ',max_gain,ops,'\n')

    #raise NameError("does this work?")

    output_text = output_text+'Case #'+str(case_num)+': '+str(ops)+'\n'

    case_start_line += 2
    case_num += 1

output_file.write(output_text)
output_file.close()
print(output_text)
