import numpy as np
from os.path import join

def solve(C, F, X):

    rate = 2.0
    time = 0

    dt1 = C / rate + X / (rate + F) # going for cookie farm
    dt2 = X / rate # ignore cookie farm
    while (dt1 < dt2):
        time += C / rate
        rate += F
        dt1 = C / rate + X / (rate + F) # going for cookie farm
        dt2 = X / rate # ignore cookie farm

    time += dt2

    return time


if __name__=='__main__':

    directory = '/home/paul/large/personal/programming/code-jam/2014/round_0'
    # name = 'B-small-attempt0'
    # name = 'B-small'
    name = 'B-large'    
    filename = join(directory, '%s.in' % name)
    fout = open(join(directory, '%s.out' % name), 'w')

    with open(filename, 'r') as fin:
        T = int(fin.readline())
        # print 'T = %d' % T
        for t in range(T):
            # print 't = %d' % t
            C, F, X = np.array([float(a) for a in fin.readline().split()])
            time = solve(C, F, X)
            fout.write('Case #%d: %1.7f\n' % (t + 1, time))

    fout.close()
    




    
    
    
    
