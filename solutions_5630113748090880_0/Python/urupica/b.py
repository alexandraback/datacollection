#!/usr/bin/python

import sys, datetime

# https://code.google.com/p/gmpy/
#import gmpy

def search(board, lists, n, k, r, c, om):
    global ret
    if ret != None:
        return
    if k == 2*n-1:
        if om != None:
            if om[0] == 0:
                ret = list(board[om[1]])
            else:
                ret = [board[i][om[1]] for i in xrange(n)]
        elif r == n-1:
            ret = list(board[n-1])
        else:
            ret = [board[i][c] for i in xrange(n)]
        return
    valid = True
    if r < n:
        for j in xrange(n):
            if board[r][j] != None and lists[k][j] != board[r][j]:
                valid = False
                break
            if r > 0 and lists[k][j] <= board[r - 1][j]:
                valid = False
                break
        if valid:
            old = list(board[r])
            for j in xrange(n):
                board[r][j] = lists[k][j]
            search(board, lists, n, k+1, r+1, c, om)
            for j in xrange(n):
                board[r][j] = old[j]
    valid = True
    if om == None and r+1 < n:
        for j in xrange(n):
            if board[r+1][j] != None and lists[k][j] != board[r+1][j]:
                valid = False
                break
            if lists[k][j] <= board[r][j]:
                valid = False
                break
        if valid:
            old = list(board[r+1])
            for j in xrange(n):
                board[r+1][j] = lists[k][j]
            search(board, lists, n, k+1, r+2, c, (0, r))
            for j in xrange(n):
                board[r+1][j] = old[j]

    valid = True
    if c < n:
        for i in xrange(n):
            if board[i][c] != None and lists[k][i] != board[i][c]:
                valid = False
                break
            if c > 0 and lists[k][i] <= board[i][c - 1]:
                valid = False
                break
        if valid:
            old = [board[i][c] for i in xrange(n)]
            for i in xrange(n):
                board[i][c] = lists[k][i]
            search(board, lists, n, k+1, r, c+1, om)
            for i in xrange(n):
                board[i][c] = old[i]
    valid = True
    if om == None and c+1 < n:
        for i in xrange(n):
            if board[i][c+1] != None and lists[k][i] != board[i][c+1]:
                valid = False
                break
            if lists[k][i] <= board[i][c]:
                valid = False
                break
        if valid:
            old = [board[i][c+1] for i in xrange(n)]
            for i in xrange(n):
                board[i][c+1] = lists[k][i]
            search(board, lists, n, k+1, r, c+2, (1, c))
            for i in xrange(n):
                board[i][c+1] = old[i]



def solve(n, lists):
    global ret
    ret = None
    lists.sort()
    board = [lists[0]] + [[None]*n for i in xrange(n-1)]
    search(board, lists, n, 1, 1, 0, None)
    return ' '.join(map(str, ret))


def parse(input_file):
    n = int(input_file.readline().strip())
    lists = []
    for i in xrange(2*n - 1):
        lists.append(map(int, input_file.readline().strip().split()))
    return (n, lists)

def main():
    start = datetime.datetime.now()
    input_file = open(sys.argv[1])
    output_file = open(sys.argv[2], "w") if len(sys.argv) > 2 else None
    print "Writing to %s" % sys.argv[2] if output_file else "No output file"
    test_cases = int(input_file.readline().strip())
    print "Test cases:",test_cases
    print '-----------------'
    for tc in xrange(1, test_cases + 1):
        output = "Case #%d: %s" % (tc, solve(*parse(input_file)))
        print output
        if output_file:
            output_file.write(output + "\n")
    print '-----------------'
    print "Written to %s" % sys.argv[2] if output_file else "No output file"
    print 'Elapsed time: %s' % (datetime.datetime.now() - start)
    input_file.close()
    if output_file:
        output_file.close()

if __name__ == "__main__":
    main()
