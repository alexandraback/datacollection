# C.py

import sys
import os

def main():
    s = ' '.join(sys.stdin.readlines()).split()
    os.close(0)

    N = int(s[0])
    s = s[1:]
    for i in range(N):
        count = 0
        A = int(s[2 * i])
        B = int(s[2 * i + 1])
        for j in range(A, B + 1):
            count += countrun(j, A, B)

        print 'Case #%s: %s' % (i+1, count)

def countrun(j, A, B):
    strj = str(j)
    perms = list(set([int(strj[i:] + strj[:i]) for i in range(len(strj))]))
    perms = filter(lambda X: A <= X <= B, perms)
    if min(perms) == j:
        return len(perms) * (len(perms)-1) / 2 
    else:
        return 0

if __name__ == "__main__":
    main()
