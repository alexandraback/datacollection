def min_expected(A, B, probs):
    cumulative_probs = [0]
    for i, p in enumerate(probs):
        i+=1
        cumulative_probs.append((1-p)*cumulative_probs[i-1]+p*cumulative_probs[i-1]+(1-p)*(1-cumulative_probs[i-1]))
    expected_enter = B+2
    expected_keep_typing = (B-A+1)*(1-cumulative_probs[len(probs)])+(2*B-A+2)*(cumulative_probs[len(probs)])
    #print 'expected_keep_typing: ' + str(expected_keep_typing)
    #print B-A+1
    #print 1-cumulative_probs[len(probs)]
    expected_i_backspaces = []
    for i in range(1,len(probs)+1):
        """
        print 'number of backspaces: ' + str(i)
        print 'prob_incorrect: ' + str(cumulative_probs[-i-1])
        print 'prob_correct: ' + str(1-cumulative_probs[-i-1])
        print 'keys_incorrect: ' + str(2*B-A+2+2*i)
        print 'keys_correct: ' + str(B-A+1+2*i)
        """
        expected_i_backspaces.append((2*B-A+2+2*i)*cumulative_probs[-i-1] + (B-A+1+2*(i))*(1-cumulative_probs[-i-1]))
    #print cumulative_probs
    #print expected_i_backspaces
    return min(expected_i_backspaces+[expected_enter]+[expected_keep_typing])

print min_expected(2,5,[0.6,0.6])
print min_expected(1,20,[1])
print min_expected(3,4,[1,0.9,0.1])

input_file = open('A-large.in')
output_file = open('output', 'w')
current_line = 0
test_case = [0,0,0]
test_count = 1
for i, line in enumerate(input_file.readlines()):
    if i==0:
        continue
    else:
        line_data = line.split()
        if current_line == 0:
            test_case[0] = int(line_data[0])
            test_case[1] = int(line_data[1])
            current_line = 1
        else:
            #print '\nTest case %d'%(test_count)
            test_case[2] = [float(p) for p in line_data]
            output_file.write('Case #%s: %s\n' %(test_count, min_expected(test_case[0], test_case[1], test_case[2])))
            test_count+=1
            current_line = 0
        #do something relevant
        #numbers = map(int, line.split())
        #count = single_case(numbers[0], numbers[1], numbers[2], numbers[3:])
        #output_file.write('Case #%d: %d\n' % (i, count))
input_file.close()
output_file.close()


