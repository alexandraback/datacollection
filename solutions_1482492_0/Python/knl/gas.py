import fileinput
import math

def solve(tests):
    [D, N, A] = tests.readline().split()
    D = float(D)
    N, A = int(N), int(A)
    t, d = [0]*N, [0]*N
    
    for i in range(0, N):
       [t[i], d[i]] = map(float, tests.readline().split()) 
    a = map(float, tests.readline().split())

    for i in range(0, A):
        accn = a[i]
        prev_v = 0
        prev_t = 0
        prev_d = 0

        j = 0
        for j in range(1, N):
            time = t[j]
            distance = d[j]

            if distance >= D:
                break
        
            del_t = time - prev_t
            del_d = distance - prev_d

            min_accn = 2 * (del_d - prev_v * del_t) / (del_t * del_t)

            if (accn > min_accn):
                prev_d = distance
                usable_accn = 2*(del_d - prev_v * del_t)/(del_t*del_t)
                prev_v = prev_v + usable_accn*del_t
            else:
                prev_d = prev_v * del_t + .5 * accn * del_t * del_t
                prev_v = prev_v + accn * del_t

            prev_t = time

        s = D - prev_d
        fastest_t = (math.sqrt(prev_v*prev_v + 2*accn*s) - prev_v)/accn + prev_t
        min_t = 0 if j == 0 else t[j-1] + (t[j]-t[j-1])*(D-d[j-1])/(d[j]-d[j-1])

        print max(fastest_t, min_t)




if __name__ == "__main__":
    tests = fileinput.FileInput()
    T = int(tests.readline())

    for i in range(0,T):
        print "Case #{}: ".format(i+1)
        solve(tests)
