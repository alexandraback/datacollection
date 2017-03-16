'''
Created on Apr 26, 2013

@author: Andrew
'''
import sys

sample = '''1
100 3 5 7
4 2 12 1 6 1 1
3 12 4 12 3 36 1
2 12 6 2 3 1 3
15 1 3 25 1 1 3
1 45 15 5 1 15 45
10 50 1 2 1 5 2
6 6 6 2 9 9 18
1 10 50 1 5 10 25
18 6 6 3 2 6 6
3 1 15 1 1 30 1
2 1 1 30 5 3 30
9 12 1 12 9 3 3
5 45 9 3 1 3 45
10 5 20 2 1 1 4
4 3 12 3 9 3 9
24 24 2 3 8 8 12
10 5 2 2 2 2 10
24 1 24 3 8 3 6
5 20 80 20 4 4 80
20 5 1 5 25 1 100
3 2 15 3 3 30 15
5 1 5 25 75 75 15
25 1 25 5 1 5 25
5 5 4 20 2 10 40
4 1 4 4 4 4 16
3 1 3 36 9 3 3
9 9 9 3 3 9 9
5 60 1 20 5 60 60
15 15 15 15 25 15 1
4 15 3 3 20 3 60
25 5 5 10 50 10 25
9 3 3 3 9 9 1
8 8 8 1 4 4 2
25 5 5 125 5 5 25
30 3 2 30 6 6 2
15 15 15 1 9 9 15
2 40 40 20 2 2 40
20 20 1 20 4 5 4
5 5 25 25 1 25 5
3 12 9 4 12 1 3
1 3 1 4 1 24 12
3 1 9 1 9 3 9
3 9 9 3 9 1 9
1 8 1 1 40 5 1
20 1 5 15 60 1 15
5 8 8 1 40 40 1
4 20 20 80 5 4 20
5 25 25 25 5 75 5
20 20 5 20 10 4 10
20 4 15 3 1 15 15
1 3 3 3 18 9 3
5 10 2 5 10 25 50
20 5 10 10 4 4 5
5 1 25 125 25 25 5
10 1 20 5 40 10 10
4 10 10 2 4 10 5
15 9 3 15 1 9 45
4 2 2 4 1 8 8
1 8 16 16 4 8 4
24 2 12 24 8 24 1
25 75 3 5 3 15 15
1 4 8 4 1 16 8
1 15 75 5 3 75 1
4 1 5 4 5 20 4
9 3 4 12 12 3 12
5 15 10 2 5 15 2
5 50 10 10 2 2 2
2 10 10 20 1 4 1
4 20 5 20 16 1 5
5 30 10 6 2 2 1
16 8 1 32 4 2 4
10 2 10 4 5 2 4
5 5 5 5 4 40 10
8 4 6 3 1 1 12
100 20 5 20 5 20 1
1 10 2 20 4 4 5
60 4 3 4 20 12 5
12 6 8 8 6 6 2
9 45 3 5 3 45 15
3 4 4 60 1 4 4
12 1 12 12 48 1 48
64 4 64 64 1 64 1
4 20 20 12 5 5 12
1 8 24 8 4 1 24
12 12 60 12 5 20 20
4 16 4 4 1 4 1
10 10 1 5 5 2 25
12 4 36 1 9 12 12
30 1 3 1 10 30 6
25 25 3 15 25 15 3
20 20 25 20 100 100 100
4 12 1 2 2 4 6
16 48 4 48 1 12 16
16 5 4 4 16 16 80
12 3 12 1 3 12 12
1 10 30 30 3 3 15
100 4 20 4 1 25 25
15 75 5 75 15 5 75
4 32 4 1 8 8 8
10 15 15 30 15 5 10
'''.splitlines()

sampleo='''223
334
223
355
335
255
233
255
233
235
235
334
335
225
334
234
225
234
445
455
235
355
555
245
444
334
333
345
355
345
255
333
224
555
235
335
245
455
555
334
234
333
333
245
345
245
445
355
225
345
233
255
225
555
245
225
335
224
244
234
355
224
355
245
334
235
255
225
445
235
244
225
245
234
455
225
345
234
335
345
344
444
345
234
345
444
255
334
235
355
455
223
344
445
334
235
455
355
244
235
'''.splitlines()

def raw_input_test():
    global sample
    if len(sample) == 0:
        return ''
    ret = sample[0]
    sample = sample[1:]
    return ret

def _print(x):
    print x
    
# == FUNCTIONS == #
 
d = dict()
M = 5
for x in xrange(1,M + 1):
    for y in xrange(1,M + 1):
        for z in xrange(1,M + 1):
            s = x*y*z
            if s not in d:
                d[s] = []
            L = sorted([x,y,z])
            L = [e for e in L if e != 1]
            if L not in d[s]:
                d[s].append(L)

'''import random
R = []
for r in xrange(100):
    N = [random.randint(2,5) for x in xrange(3)]
    L = []
    for t in xrange(7):
        s = 1
        for x in N:
            if random.random() > 0.5:
                s *= x
        L.append(s)
    R.append((N,L))
    
for n,l in R:
    print ' '.join(map(str,l))
for n,l in R:
    print ''.join(map(str,sorted(n)))
exit()'''
def combine(x, y):
    for e in set(y):
        cx = x.count(e)
        cy = y.count(e)
        for t in xrange(cy - cx):
            x.append(e)

def solve(K):
    global d
    priors = [d[x] for x in K]
    #print priors
    result = []
    for prior in priors:
        prior = prior[0]
        combine(result, prior)
    
    return result

# == MAIN == #
if len(sys.argv) > 1:
    fn = sys.argv[1]
    f = open(fn, 'r')
    gn = fn.rsplit('.',1)
    gn = gn[0] + '.out'
    g = open(gn, 'w')
    getline = lambda: f.readline().strip('\n')
    printline = lambda x: g.write(str(x) + '\n')
else:
    getline = raw_input_test
    printline = _print


#####################
num_cases = int(getline())

c = 0
for case_num in xrange(1,num_cases + 1):
    R, N, M, K = map(int, getline().split())
    msg = ''
    for r in xrange(R):
        L = map(int, getline().split())
        result = solve(L)
        while len(result) < N:
            result.append(2)
        if len(result) > 3:
            result = result[0:3]
        result = sorted(result)
        result = ''.join(map(str,result)) + '\n'
        #if result.strip('\n') == sampleo[0]:
        #    c += 1
        #sampleo = sampleo[1:]
        msg += result
    printline("Case #{0}:\n{1}".format(case_num, msg))
#####################
if len(sys.argv) > 1:
    f.close()
    g.close()