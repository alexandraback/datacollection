import fileinput


def run(bffs):
    bffs = [bff-1 for bff in bffs]
    n = len(bffs)
    cycles = []
    lines = []
    
    heads = set(range(n)) - set(bffs)
    if len(heads) == 0:
        heads = set(range(n)) 
    
    scores = [0] * n

    for h in heads:
        # print h
        passes = set([h])
        path = [h]
        
        # score = 0
        # scores[h] = 0

        curr = h
        quit = False
        while bffs[curr] not in passes:
            nextt = bffs[curr]
            # print 'next:', nextt

            
            passes.add(nextt)
            path.append(nextt)
            curr = nextt
        
        # print 'path:', path, 'curr:', curr

        # 3<-->10
        if path[-1] == bffs[bffs[curr]] and len(path) > 2:
            found = False
            for i,l in enumerate(lines):
                if l[-1] == curr:
                    found = True
                    if len(l) < len(path):
                        lines[i] = path
                    break
            if not found:
                lines.append(path)
                
        else: 
            path = path[path.index(bffs[curr]):]
            # print path
            cycles.append(path)

    # print 'lines:', lines
    tails = dict()
    for l in lines:
        if not l[-2] in tails:
            tails[l[-1]] = len(l)
        else:
            tails[l[-2]] += len(l)-2
    
    # print 'tails:', tails

    max_in_lines = max(tails.values() + [0])
    max_in_cycles = max(map(len, cycles) + [0])
    
    # print 'max in line:', max_in_lines
    # print lines
    # print 'max in cycle:', max_in_cycles

    return max(max_in_lines, max_in_cycles)


def main():
    # inputs = [0, 1, 2, 11, 1692]
    inputs = []
    
    for line in fileinput.input():
        inputs.append(line.strip())

    T = int(inputs[0])
    start = 1
    for t in xrange(T):
        # print 'begin ', t
        n = int(inputs[start])
        dd = map(int, inputs[start+1].split())
        start += 2
        
        res = run(dd)
        print 'Case #%d: %d' % (t+1, res)
            

if __name__ == '__main__':
    main()

