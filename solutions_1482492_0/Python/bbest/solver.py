import sys, math

def time_to_travel(accel, v_o, d):
    return (-v_o + math.sqrt(v_o**2+2*accel*d)) / (accel)

def collision(accel, v_o, d, t):
    if time_to_travel(accel, v_o, d) < t:
        return True
    return False

def solver(d, n, a, ps, accels):
    answers = []
    for accel in accels:
        # case where n is 1
        # relevant ps
        for i in xrange(len(ps)):
            if ps[i][1] > d:
                ps = ps[:i+1]
                break
        n = len(ps)
        if n == 1:
            answers.append(time_to_travel(accel, 0, d))
        else:
            first_v = (ps[1][1] - ps[0][1]) / (ps[1][0] - ps[0][0])
            t_o = ps[0][1] / first_v
            ps[0] = [-t_o, 0]
            p = ps[-1]
            prev_p = ps[-2]
            last_v = (p[1] - prev_p[1]) / (p[0] - prev_p[0])
            p_at_d = [prev_p[0] + (d - prev_p[1]) / last_v, d]
            ps.pop()
            ps.append(p_at_d)
            debug(ps)
            car_v = 0
            constrained_at = None
            assert(ps[0][1] == 0)
            assert(ps[-1][1] == d)
            assert(ps[0][0] <= 0)
            for (idx, p) in enumerate(ps[1:]):
                dist = p[1] - ps[idx][1]
                car_time = time_to_travel(accel, car_v, dist)
                block_time = ps[idx][0] > 0 and p[0] - ps[idx][0] or p[0]
                if car_time < block_time:
                    constrained_at = p
                car_v = math.sqrt(2*accel*p[1])

            if constrained_at:
                time_to_constraint = constrained_at[0]
                remaining_time = time_to_travel(accel, math.sqrt(2*accel*constrained_at[1]), (d - constrained_at[1]))
                total_time = time_to_constraint + remaining_time
            else:
                total_time = time_to_travel(accel, 0, d)
            answers.append(total_time)
    return '\n' + '\n'.join(["%.7f" % a for a in answers])



def ssi(s):
    """
    space separated integers
    """
    return map(int, s.strip('\n').split())

def rl():
    return sys.stdin.readline()

def debug(msg='', off=False):
    if not off:
        sys.stderr.write(str(msg) + '\n')

def main():
    # open input file
    # input_file = open('infile.txt')
    
    cases = int(rl())
    output = []
    # loop through cases passing input to solver
    for c in xrange(cases):
        s = rl()
        [d, n, a] = s.strip('\n').split()
        d = float(d)
        n = int(n)
        a = int(a)
        ps = []
        for i in xrange(n):
            s = rl()
            [t, x] = s.strip('\n').split()
            t = float(t)
            x = float(x)
            ps.append([t, x])
        s = rl()
        accels = map(float, s.strip('\n').split())
        answer = solver(d, n, a, ps, accels)
        output.append('Case #%d:%s\n' % (c+1, answer))
    # open output file
    output_file = sys.stdout
    # write ouput to file
    output_file.writelines(output)
    output_file.flush()



if __name__=='__main__':
    main()
