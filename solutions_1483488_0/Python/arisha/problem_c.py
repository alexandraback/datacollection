input_file = open('/Users/arisha/Downloads/C-small-attempt0 (1).in')
output_file = open('/Users/arisha/Documents/C-small.out', 'w')

T = int(input_file.readline())

def get_pairs(A, B):
    digits = len(str(A))
    count = 0
    for i in range(A, B+1):
        pair_list = []
        num = str(i)
        for i in range(1, digits):
            pair = num[i:] + num[:i]
            if int(num) < int(pair) and int(pair) <= B and pair not in pair_list:
                count+= 1
                pair_list.append(pair)
    return count

for i in range(T):
    curr_test = map(int, input_file.readline().strip().split(' '))
    A, B = curr_test[0], curr_test[1]
    output_file.write("Case #%d: %d\n" %(i+1, get_pairs(A, B)))
    
input_file.close()
output_file.close()
