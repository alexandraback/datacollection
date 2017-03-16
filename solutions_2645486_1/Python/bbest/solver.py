import sys

DEBUG = True

def solver(e, r, n, vs):
    if r >= e:
        total = 0
        for v in vs:
            total += v * e
        return total
    gain = 0
    enum_vs = list(enumerate(vs))
    enum_vs.sort(key=lambda x: x[1], reverse=True)
    back_constraints = [0] * n
    forward_constraints = [e] * n
    refresh_period = e / r
    finished = []
    if e % r:
        refresh_period += 1
    for idx, v in enum_vs:
        gain += v * (forward_constraints[idx] - back_constraints[idx])
        past_back = back_constraints[idx]
        i = idx + 1
        back_constraints[idx] = forward_constraints[idx]
        forward_constraints[idx] = past_back
        finished.append(idx)
        for i in range(refresh_period):
            if idx + i + 1 >= len(vs) or (idx+i+1) in finished:
                break
            forward_constraints[idx+i+1] = min(forward_constraints[idx] + r * (i + 1), e)
        for i in range(1, refresh_period + 1):
            if idx - i < 0:
                break
            back_constraints[idx-i] = max(back_constraints[idx-i], max(back_constraints[idx] - (r*i), 0))

    return gain

def ssi(s, func=int):
    """
    space separated integers
    """
    return map(func, s.strip('\n').split())

def rl():
    return sys.stdin.readline()

def debug(*args):
    if args[-1] is not False and DEBUG:
        msg = " ".join([str(m) for m in args])
        sys.stderr.write(msg + '\n')

def main():
    # open input file
    # input_file = open('infile.txt')
    
    cases = int(rl())
    output = []
    # loop through cases passing input to solver
    for c in xrange(cases):
        debug('Case #%d' % (c+1))
        e, r, n = ssi(rl())
        vs = ssi(rl())
        answer = solver(e, r, n, vs)
        output.append('Case #%d: %s\n' % (c+1, answer))
    # open output file
    output_file = sys.stdout
    # write ouput to file
    output_file.writelines(output)
    output_file.flush()



if __name__=='__main__':
    main()
