import numpy as np
from os.path import join

def score_war_fluke(x, y):

    n = len(x)
    points = 0
    i = 0
    j = 0

    while i < n and j < n:
        if x[i] < y[j]:
            i += 1
            j += 1
            points += 1 
        else:
            j += 1

    points += n - i - 1
    
    return points
    
def score_war(x, y):

    n = len(x)
    points = 0
    i = 0
    j = 0

    while i < n and j < n:
        if x[i] < y[j]:
            i += 1
            j += 1
        else:
            j += 1
            points += 1

    return points
    
def score_war_deceit(x, y):

    n = len(x)
    points = 0
    i1 = 0
    i2 = n - 1
    j = n - 1

    while i1 <= i2:
        if x[i2] < y[j]:
            i1 += 1
            j -= 1
        else:
            i2 -= 1
            j -= 1
            points += 1
    
    return points


if __name__=='__main__':

    directory = '/home/paul/large/personal/programming/code-jam/2014/round_0'
    name = 'D-small-attempt1'
    # name = 'D-small'
    # name = 'D-large'    
    filename = join(directory, '%s.in' % name)
    fout = open(join(directory, '%s.out' % name), 'w')

    with open(filename, 'r') as fin:
        T = int(fin.readline())
        print 'T = %d' % T
        for t in range(T):
            N = int(fin.readline())
            x = np.array([float(a) for a in fin.readline().split()])
            y = np.array([float(a) for a in fin.readline().split()])            
            x.sort()
            y.sort()
            # print x
            # print y
            s1 = score_war_deceit(x, y)
            s2 = score_war(x, y)
            fout.write('Case #%d: %d %d\n' % (t + 1, s1, s2))
            print('Case #%d: %d %d' % (t + 1, s1, s2))

    fout.close()
