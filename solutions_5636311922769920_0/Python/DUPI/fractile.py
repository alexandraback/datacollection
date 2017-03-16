import os
os.chdir('/Users/mac/OneDrive/competitions/codejam 2016/fractile')


##read test.in
test_f = open('./tests/D-small-attempt0.in.txt')
out_f = open('./tests/small.out.txt', 'w+')
test_num = None
test_case_num = 1
for line in test_f:
    if test_num == None:
        test_num = int(line)
    else:
        k, c, s = line.strip().split(' ')
        k = int(k)
        c = int(c)
        s = int(s)
        assert s == k
        output = ' '.join([str(x) for x in range(1, k+1)])
        #print '{}, {}, {}'.format(max_s, audiences, extra_need) 
        out_f.write('Case #{}: {}\n'.format(test_case_num, output))
        test_case_num += 1
        
test_f.close()
out_f.close()