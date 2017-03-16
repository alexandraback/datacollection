import sys,os

def get_int(f):
    return int(f.readline())

def get_line_int(f):
    return map(int,f.readline().split())

def do_all(file_name):
    file_name1 = os.path.splitext(file_name)[0]+'.out'
    with open(file_name) as f1:
        with open(file_name1,'w') as f2:
            calculation(f1,f2)

def prime(n):
    for i in (2,3,5,7):
        if i>n:
            break
        yield i

def calculation(f_in,f_out):
    n = get_int(f_in)
    for case in xrange(1,n+1):
        R,N,M,K = get_line_int(f_in)
        print >>f_out,'Case #%s:'%case
        for i in xrange(R):
            L = {}
            for m in prime(M):
                L[m] = []
            for num in get_line_int(f_in):
                d = {}
                for m in prime(M):
                    while num%m == 0:
                        d[m] = d.get(m,0)+1
                        num/=m
                for key in d:
                    L[key].append(d[key])
            result = []
            for m in prime(M):
                if m == 2:
                    continue
                if L[m]:
                    result.append((m,max(L[m])))
            two = L[2]
            if two:
                t = min(two)
                two = map(lambda x:x/t,two)
                t = t.bit_length()
                print two
                for i in xrange(max(two).bit_length()):
                    result.append((1<<(i+t),1))
            if result:
                nn = N - sum(zip(*result)[1])
            else:
                nn = N
            result.append((2,nn))
            A = ''.join(map(lambda X:str(X[0])*X[1],result))
            print A
            print >>f_out,A[:N]

if __name__ == '__main__':
    do_all(sys.argv[1])
