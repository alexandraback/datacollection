import os
os.chdir('/Users/mac/OneDrive/competitions/codejam 2016/pancake')

##extra_need
def flip(s):
    new_s = ''
    for c in s[::-1]:
        if c == '-':
            new_s += '+'
        else:
            new_s += '-'
    return new_s

def getT(s):
    if len(s) == 0:
        return 0
    if (s[-1] == '+'):
        return getT(s[:-1])
    if (s[0] == '-'):
        return 1+getT(flip(s))
    i = 1
    while (i <= len(s)):
        if s[-i] == '+':
            break
        i += 1
    return 1+getT(flip(s[:-(i-1)]) + s[-(i-1):])
        
    


##read test.in
test_f = open('./tests/B-small-attempt0.in.txt')
out_f = open('./tests/A-small-practice.out.txt', 'w+')
test_num = None
test_case_num = 1
for line in test_f:
    if test_num == None:
        test_num = int(line)
    else:
        s = line.strip()
        T = getT(s)
        #print '{}, {}, {}'.format(max_s, audiences, extra_need) 
        out_f.write('Case #{}: {}\n'.format(test_case_num, T))
        test_case_num += 1
        
test_f.close()
out_f.close()