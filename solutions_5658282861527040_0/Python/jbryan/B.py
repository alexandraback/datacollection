input_file = open('B-small-attempt0.in','r')
raw_input = input_file.read()

lines = raw_input.split('\n')

num_cases = int(lines[0])
case_num = 1

output_text = ''
output_file = open('A.out','w')
output_text = ''

def dec_to_bin(x):
    return int(bin(x)[2:])

debug=1

while case_num<=num_cases:
    A,B,K = map(int,lines[case_num].split(' '))
    if debug: print(A,B,K)

    count = 0
    for i in range(A):
        for j in range(B):
            if i&j<K: count += 1

    output_text += 'Case #'+str(case_num)+': '+str(count)+'\n'

    case_num += 1

if debug: print(output_text)

output_file.write(output_text)
input_file.close()
output_file.close()
