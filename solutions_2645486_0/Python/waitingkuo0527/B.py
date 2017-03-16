from collections import Counter


    

def solve(E, R, N, V):

    ans = 0
    if R >= E:
        for v in V: ans += E * v
        return ans
    V.sort(reverse=True)

    ans += V[0] * E

    now = R

    dist = E - R
    times = (E - 1)/ R + 1

    U = N-1
    full = U / times
    remain = U / times
    r = U % times
    if r == 0:
        partial = 0
        partial_times = 0
    else:
        partial = 1 
        some_R = r * R

    for v in V[1:1+full]:
        ans += v * E

    for v in V[1+full:1+full+partial]:
        if partial == 1:
            ans += v * some_R
    
    for v in V[1+full+partial:1+full+partial+remain]:
        ans += ((R-(E%R))%R) * v

    return ans

def solve2(E, R, N, V):

    ans = 0

    if R >= E:
        for v in V: ans += E * v
        return ans

    V.sort(reverse=True)

    i = 0
    j = N - 1
    now = E

    while True:
        if i == j: 
            ans += now * V[i]
            break
        else:
            if now == E: 
                ans += now * V[i] 
                i += 1
                now = R
            else:
                if R - (E - now) >= 0:
                    ans += (R - (E-now)) * V[j]
                    j -= 1
                    now = E
                else:
                    now += R
                    j -= 1


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

        E, R, N = [int(x) for x in f_in.readline().split()]
        V = [int(x) for x in f_in.readline().split()]

        # Solve
        ans = solve(E, R, N, V)
        print ans

        ## Output
        f_out.write('Case #%d: %s\n' % (case, ans))

        

