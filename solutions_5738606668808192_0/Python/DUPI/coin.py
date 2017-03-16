import os
os.chdir('/Users/mac/OneDrive/competitions/codejam 2016/coin')

##extra_need
dig_cache = {}
max_divisor = 10^10

def find_divisor(x):
    i = 2
    while (i<x and i<500):
        if x % i == 0:
            return i
        i += 1
    return -1

def get_interpret_of_base(s, b):
    v = 0
    for i,x in enumerate(s):
        if x == '1':
            v += b**(len(s)-i-1)
    return v

def get_interprets(s):
    interprets = []
    for b in range(2, 11):
        interprets.append(get_interpret_of_base(s, b))
    return interprets

import random
def generator(N):
    generated = set([])
    while (len(generated) < 2**(N-2)):
        new_s = "1"
        for i in range(N-2):
            if random.random() > 0.5:
                new_s += '1'
            else:
                new_s += '0'
        new_s += '1'
        if new_s not in generated:
            generated.add(new_s)
            yield new_s

def get_divisors(s):
    interprets = get_interprets(s)
    divisors = []
    for x in interprets:
        d = find_divisor(x)
        if d == -1:
            return None
        else:
            divisors.append(d)
    return divisors

def generate_coins(N, J):
    output = ""
    for s in generator(N):
        if (J == 0):
            break
        divisors = get_divisors(s)
        if (divisors == None):
            continue
        divisors = [str(d) for d in divisors]
        output += str(s) + ' ' + ' '.join(divisors) + '\n'
        J -= 1
    assert J == 0
    return output
    
##
out_f_small = open('./tests/small.out.txt', 'w+')
out_f_small.write('Case #1:\n')
out_f_small.write(generate_coins(16, 50))
out_f_small.close()


out_f_large = open('./tests/large.out.txt', 'w+')
out_f_large.write('Case #1:\n')
out_f_large.write(generate_coins(32, 500))
out_f_large.close()
        

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