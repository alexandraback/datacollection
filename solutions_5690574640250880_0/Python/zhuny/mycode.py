def do():
    count = input()
    for i in xrange(count):
        print "Case #%d:"%(i+1),
        calculate()

def get_partition(N,start,max_length):
    if N == 1 or start*max_length<N or N==start+1:
        return []
    L = [start]*(N/start)
    if N%start > 0:
        L.append(N%start)
    if N%start == 1:
        if start == 2:
            return []
        L[-2]-=1
        L[-1]+=1
    return L

def get_list(count,row,col):
    while 1<col:
        if col*2 == count:
            return [col,col]
        if col*2+2 <= count:
            L = get_partition(count-col,col,row-1)
            if sum(L) == count-col:
                L.insert(0,col)
                return L
        col -= 1
    return []

def calculate():
    R,C,M = map(int,raw_input().split())
    print
    empty = R*C-M
    if empty == 1:
        print 'c'+'*'*(C-1)
        for i in xrange(1,R):
            print '*'*C
        return
    if 1==R or 1==C:
        if R*C < M+2:
            print "impossible"
        elif R == 1:
            print "c"+"."*(R*C-M-1)+"*"*(M)
        else:
            print "c"
            for i in xrange(R*C-M-1):
                print '.'
            for i in xrange(M):
                print '*'
        return
    if 4<=empty:
        L = get_list(empty,R,C)
        if L:
            while len(L) < R:
                L.append(0)
            for i,count in enumerate(L):
                line = '.'*count+'*'*(C-count)
                if i == 0:
                    line = 'c'+line[1:]
                print line
            return
    print "Impossible"


if __name__ == '__main__':
    do()
