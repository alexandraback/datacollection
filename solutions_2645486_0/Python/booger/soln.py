def maxgain(E, R, acts):
    d = dict()
    # about to do activity at index timestep
    def dyn_maxgain(cur_e, timestep):
        if cur_e > E:
            cur_e = E

        if (cur_e, timestep) in d:
            return d[(cur_e, timestep)]

        if timestep == len(acts):
            return 0
        if timestep == len(acts)-1 or acts[timestep] == max(acts):
            a = acts[timestep]*cur_e + dyn_maxgain(R, timestep+1)
            d[(cur_e, timestep)] = a
            return a

        a = max([acts[timestep]*e + dyn_maxgain(cur_e-e+R, timestep+1) for e in range(0, cur_e+1, 1)])
        d[(cur_e, timestep)] = a
        return a

    return dyn_maxgain(E, 0)

def run(filename):
    lines = [line.strip() for line in open(filename) if line.strip()]
    numcases = int(lines[0])
    cur_case = 1
    cur_line = 1
    while cur_case <= numcases:
        E, R, N = [int(elt) for elt in lines[cur_line].split()]
        # print E, R, N
        cur_line += 1
        acts = [int(elt) for elt in lines[cur_line].split()]
        cur_line += 1
        print 'Case #%i: %i' % (cur_case, maxgain(E, R, acts))
        cur_case += 1

run('small_input.txt')
