import numpy as np

def and_op(x, y):
    return x and y

def solve(filename):
    fin = open(filename + '.in', 'r')
    fout = open(filename + '.out', 'w')

    T = int(fin.readline())
    for case in xrange(T):
        N, M = map(int, fin.readline().strip().split(' '))
        lawn = None
        if N == 1:
            lawn = np.array([map(int, fin.readline().strip().split(' '))], np.int)
        else:
            for i in xrange(N):
                row = np.array(map(int, fin.readline().strip().split(' ')), np.int)
                if lawn is None:
                    lawn = row
                else:
                    lawn = np.vstack((lawn, row))
        print lawn
        #this method only works for small case
        check_lawn = (lawn == 1)
        answer = 'YES'
        for i in xrange(N):
            for j in xrange(M):
                if check_lawn[i, j]:
                    if (not reduce(and_op, check_lawn[i,:].tolist())) and (not reduce(and_op, check_lawn[:,j].tolist())):
                        answer = 'NO'
                        break
            if answer == 'NO':
                break
        print answer
        fout.write(('Case #%d: ' % (case + 1)) + str(answer) + '\n')

    fin.close()
    fout.close()

if __name__ == "__main__":
    # solve("B-tiny")
    solve("B-small-attempt0")
    # solve("A-large")