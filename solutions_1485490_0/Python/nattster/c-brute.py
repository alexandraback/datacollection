def read_ints():
    a = raw_input().split()
    return [int(x) for x in a]

def read_int():
    return read_ints()[0]

def cal(Y, Z):
    if Y[1] == Z[1]:
        return min(Y[0], Z[0])
    return 0

def solve():
    N, M = read_ints()
    if N < 3 or M < 3: return normal_solve(N, M)
    x = read_ints()
    y = read_ints()
    A = [[x[2*i], x[2*i+1]] for i in range(N)]
    B = [[y[2*i], y[2*i+1]] for i in range(M)]
    match = 0
    
    for i in range(0, M):
        matched = cal(A[0], B[i])
        A[0][0] -= matched
        B[i][0] -= matched
        for j in range(i, M):
            subm = cal(A[0], B[j])
            A[0][0] -= subm
            B[j][0] -= subm
            matched2 = cal(A[1], B[j])
            A[1][0] -= matched2
            B[j][0] -= matched2
            for k in range(i, M):
                subm3 = cal(A[0], B[k])
                B[k][0] -= subm3
                subm2 = cal(A[1], B[k])
                B[k][0] -= subm2
                matched3 = cal(A[2], B[k])+subm+subm2+subm3
                match = max(match, matched+matched2+matched3)
                B[k][0] += subm2
                B[k][0] += subm3
            A[1][0] += matched2
            B[j][0] += matched2
            B[j][0] += subm
            A[0][0] += subm
        A[0][0] += matched
        B[i][0] += matched
    return match
            
def normal_solve(N, M):
    x = read_ints()
    y = read_ints()
    A = [[x[2*i], x[2*i+1]] for i in range(N)]
    B = [[y[2*i], y[2*i+1]] for i in range(M)]
    match = 0
    while len(A) > 0 and len(B) > 0:
        if A[0][1] == B[0][1]:
            matched = min(A[0][0], B[0][0])
            match += matched
            A[0][0] -= matched
            B[0][0] -= matched
            if A[0][0] == 0: A.pop(0)
            if B[0][0] == 0: B.pop(0)
            continue
        else:
            # find nearest match for A[0]
            will_matchA = 0
            for i in range(len(B)):
                if B[i][1] == A[0][1]:
                    will_matchA = max(will_matchA, min(B[i][0], A[0][0]))# / (i+1))

            # find nearest match for B[0]
            will_matchB = 0
            for i in range(len(A)):
                if A[i][1] == B[0][1]:
                    will_matchB = max(will_matchB, min(A[i][0], B[0][0]))# / (i+1))
            if will_matchA > will_matchB:
                B.pop(0)
            else:
                A.pop(0)
    return str(match)

if __name__ == '__main__':
    T = read_int()
    for i in range(T):
        print 'Case #%d: %s' % (i+1, solve())
