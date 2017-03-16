import os
os.chdir('/Users/mac/OneDrive/competitions/codejam 2016/fractile')


##
def getoutput(k,c,s):
    if (c == 1):
        o = [i+1 for i in range(k)]
    else:
        o = []
        for y in [x for x in range(1, k/2*2+1) if x%2==1]:
            o.append(k**c/k * (y-1) + (y+1))
        if k%2 == 1: #if k is odd need to care about the last tile
            o.append(k**c)
    if len(o) > s:
        return 'IMPOSSIBLE'
    else:
        return ' '.join([str(x) for x in o])

##read test.in
test_f = open('./tests/D-large.in.txt')
out_f = open('./tests/D-large.out.txt', 'w+')
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
        if s == k:
            output = ' '.join([str(x) for x in range(1, k+1)])
        else:
            output = getoutput(k,c,s)
        #print '{}, {}, {}'.format(max_s, audiences, extra_need) 
        out_f.write('Case #{}: {}\n'.format(test_case_num, output))
        test_case_num += 1
        
test_f.close()
out_f.close()