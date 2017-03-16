

def solve(A, data, level=0):
    if not data:
        return 0
    #print '\t'*level, data
    s = A
    if s == 1:
        return len(data)
    result = 0
    for i in xrange(len(data)):
        c = data[i]
        if s > data[-1]:
            return result
        if c < s:
            s += c
        else:
            while (c >= s):
                #print '\t'*level, s
                s = s*2 - 1
                result += 1
                #print '\t'*level, result
            s += c
            result += solve(s, data[i+1:], level+1)
            #print '\t'*level, result
            return min(result, len(data) - i)
    return result

def main(f):
    T = int(f.readline())
    for i in xrange(T):
        A, N = [int(j) for j in f.readline().split()]
        data = [int(j) for j in f.readline().split()]
        assert len(data) == N
        data = sorted(data)
        result = solve(A, data)
        print "Case #{0}: {1}".format(i+1, result)

if __name__ == '__main__':
    with open('A-large.in') as f:
        main(f)