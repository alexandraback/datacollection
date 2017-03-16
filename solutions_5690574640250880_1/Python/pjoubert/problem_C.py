import numpy as np
from os.path import join

def check(R, C, M):

    z = R * C - M # non-mine squares
    if z==1:
        return True
    if R==1 or C==1:
        return True
    if R==2 or C==2:
        if z % 2 == 1:
            return False
    if z % 2 == 0:
        return z >= 4
    else:
        return z >= 9


if __name__=='__main__':

    directory = '/home/paul/large/personal/programming/code-jam/2014/round_0'
    # name = 'C-small-attempt1'
    # name = 'C-small'
    name = 'C-large'    
    filename = join(directory, '%s.in' % name)
    fout = open(join(directory, '%s.out' % name), 'w')

    with open(filename, 'r') as fin:
        T = int(fin.readline())
        print 'T = %d' % T
        for t in range(T):
            R, C, M = np.array([int(a) for a in fin.readline().split()])
            print (t+1), R, C, M
            fout.write('Case #%d:\n' % (t + 1))
            exists = check(R, C, M)
            if not exists:
                fout.write('Impossible\n')
            else:
                b = M # mines to place
                z = R * C - M # non-mine squares                
                for r in range(R):
                    y = min(C, b) # number of mines to place
                    if R >= 3 and r <= R - 4: # fourth-last row or earlier
                        if C >= 3 and y == C - 1:
                            y -= 1
                    if R >= 3 and r == R - 3: # third-last row 
                        # if b % 2 == 1 and C >= 3 and y == C - 1:
                        if C >= 3 and y == C - 1:
                            y -= 2
                        if C >= 3 and z == 9:
                            y = C - 3
                        if C >= 3 and z >= 9 and z % 2 == 1:
                            y = C - 3
                    if r == R - 2 and z != 1: # second-last row
                        y = b / 2
                        # y /= 2
                    if y == C - 1 and r < R - 1: # not last row
                        if y > 0:
                            y -= 1

                    if y > 0:
                        fout.write('*' * y)
                    if r == R - 1: # last row
                        if (C - y - 1) > 0:
                            fout.write('.' * (C - y - 1))
                        fout.write('c')
                    else:
                        fout.write('.' * (C - y))
                    fout.write('\n')
                    # if (t+1 == 117):
                    #     print b, y

                    b -= y


    fout.close()
