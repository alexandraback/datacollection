import sys

def solve(A, mlist):
    mlist_len = len(mlist)
    memo = {}
    def recur(a_cur, j):
        if memo.has_key((a_cur, j)):
            return memo[(a_cur, j)]
        if j >= mlist_len:
            return 0
        min_x = None
        if a_cur > mlist[j]:
            min_x = recur(a_cur+mlist[j], j+1)
        elif a_cur > 1:
            min_x = 1+min(recur(2*a_cur-1,j), recur(a_cur, j+1))
        else:
            min_x = 1+recur(a_cur, j+1)
        memo[(a_cur, j)] = min_x
        return min_x
    return recur(A, 0)

if __name__ == '__main__':
    fh = open(sys.argv[1], 'rb')
    T = int(fh.readline().strip())
    for i in range(1, T+1):
        A,N = [int(v) for v in fh.readline().strip().split()]
        mlist = [int(v) for v in fh.readline().strip().split()]
        print 'Case #{}: {}'.format(i, solve(A, sorted(mlist)))