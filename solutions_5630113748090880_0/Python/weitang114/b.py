import fileinput


def run(n, heights):
    s = set()
    for row in heights:
        for c in row.split():
            h = int(c)
            if h in s:
                s.remove(h)
            else:
                s.add(h)
    
    l = map(str, sorted(list(s)))

    return l


def main():
    # inputs = [0, 1, 2, 11, 1692]
    inputs = []
    
    for line in fileinput.input():
        inputs.append(line.strip())

    T = int(inputs[0])
    start = 1
    for t in xrange(T):
        n = int(inputs[start])
        heights = inputs[start+1: start + n*2]
        start += n*2
        
        res = run(n, heights)
        print 'Case #%d: %s' % (t+1, ' '.join(res).strip())
            

if __name__ == '__main__':
    main()

