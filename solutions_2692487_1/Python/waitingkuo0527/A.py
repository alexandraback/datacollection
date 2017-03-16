from collections import Counter

def solve(A, N, M):

    ans = N

    M.sort()

    print M
    
    count = 0
    for i in range(0, N):

        #print 'now is ', A
        #if count == ans: return ans

        if A > M[i]:
            A += M[i]
            #print 'absorb ', M[i]
        else:
            tmp = count + N - i
            if tmp < ans: ans = tmp

            while A <= M[i]:
                #print 'add ', A-1
                A += A - 1
                count += 1
                if count == ans: return ans
            A += M[i]

    if count < ans: ans = count

    return ans


if __name__ == '__main__':

    import sys
    
    input_file = sys.argv[1]
    output_file = input_file[:].replace('.in', '.out')


    f_in = open(input_file, 'r')
    f_out = open(output_file, 'w')

    T, = [int(x) for x in f_in.readline().split()]

    for case in range(1, T+1):
        print 
        print '====================='
        print '    ' + str(case)
        print '====================='

        A, N = [int(x) for x in f_in.readline().split()]
        M = [int(x) for x in f_in.readline().split()]

        # Solve
        ans = solve(A, N, M)
        print ans

        ## Output
        f_out.write('Case #%d: %s\n' % (case, ans))

        

