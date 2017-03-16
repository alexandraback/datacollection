from collections import Counter

def test(r, t, n):

    if n * (2*r + 2*n - 1) <= t: return True
    else: return False
    

def solve(r, t):

    ans = 0

    while True:
        print r, t
        if t >= 2*r+1:
            ans += 1
            t -= 2*r+1
            r+=2
        else:
            break

    #_min = 0
    #_max = 
    

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

        r, t = [int(x) for x in f_in.readline().split()]

        # Solve
        ans = solve(r, t)
        print ans

        ## Output
        f_out.write('Case #%d: %s\n' % (case, ans))

        

