'''
Created on Apr 26, 2013

@author: Andrew
'''
import sys

sample = '''4
5 2 2
2 1
5 2 2
1 2
3 3 4
4 1 3 5
5 2 10
1 5 8 9 2 3 4 7 8 1
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


def pick(E, R, V, e=None, at=None, answer=None, maxAnswer=None):
    if answer is None:
        answer = 0
    if at is None:
        at = 0
    if maxAnswer is None:
        maxAnswer = [0]
    if e is None:
        e = E
    if at >= len(V):
        if answer > maxAnswer[0]:
            maxAnswer[0] = answer
        return maxAnswer
    
    for P in xrange(E,-1, -1):
        if P <= e:
            newE = e - P + R
            if newE > E:
                newE = E
            pick(E, R, V, newE, at + 1, answer + V[at] * P, maxAnswer)
    
    return maxAnswer[0]

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

for case_num in xrange(1,num_cases + 1):
    
    E, R, N = map(int, getline().split())
    V = map(int, getline().split())
    
    msg = maxAnswer = pick(E, R, V)
    msg = str(msg)
    printline("Case #{0}: {1}".format(case_num, msg))


#####################
if len(sys.argv) > 1:
    f.close()
    g.close()