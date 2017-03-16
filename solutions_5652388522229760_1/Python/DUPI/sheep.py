import os
os.chdir('/Users/mac/OneDrive/competitions/codejam 2016/sheep')

##extra_need
def getT(N):
    N = int(N)
    T = 1
    cache = set([])
    digits = set([])
    while (T <= 100):
        new_N = T*N
        for d in str(new_N):
            digits.add(d)
        #cache.add(new_N)
        if (len(digits) == 10):
            return new_N
        T += 1
    return 'INSOMNIA'
    


##read test.in
test_f = open('./tests/A-large.in.txt')
out_f = open('./tests/A-large-practice.out.txt', 'w+')
test_num = None
test_case_num = 1
for line in test_f:
    if test_num == None:
        test_num = int(line)
    else:
        N = line.strip()
        T = getT(N)
        #print '{}, {}, {}'.format(max_s, audiences, extra_need) 
        out_f.write('Case #{}: {}\n'.format(test_case_num, T))
        test_case_num += 1
        
test_f.close()
out_f.close()