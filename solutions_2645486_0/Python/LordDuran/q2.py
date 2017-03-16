inputfile = file("B-small-attempt0.in", "rb")
outputfile = file("B-small.out", "wb")
out_s = "Case #%d: %d"
parse_line = lambda: [int(a) for a in inputfile.readline().split()]

T = int(inputfile.readline())


# dynamic programming

def gain(E, R, N, V, gain_arr, job_num, curr_energy):
        
    if job_num == N:
        return 0
    if gain_arr[job_num][curr_energy] != -1:
        return gain_arr[job_num][curr_energy]
    options = [
                    gain(E, R, N, V, gain_arr, job_num+1, min(curr_energy - k + R, E)) + V[job_num]*k
                    for k in range(0, curr_energy+1)
              ]
    retval = max(options)
    gain_arr[job_num][curr_energy] = retval
    return retval

for ncase in xrange(1,T+1):
    E, R, N = parse_line()
    gain_arr = [ [-1]*(E+1) for i in xrange(N) ] # gain_arr[jobnum, energy]
    V = parse_line()
    this_gain = gain(E,R,N,V,gain_arr, 0, E)
    print "This gain:", this_gain
    print >>outputfile, out_s % (ncase, this_gain)