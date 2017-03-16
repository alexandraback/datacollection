import sys

def solve(shy):
    clapping = 0
    extra = 0
    for shyLevel, count in enumerate(shy):
        count = int(count)
        if count == 0:
            continue
        # if there're clapping more than shyLevel already - they'll stand up and clap
        if shyLevel <= clapping:
            clapping += count
        else:
            # we'd need to invite some extra people with less shyness level
            extra += shyLevel - clapping
            clapping += extra + count

    if extra + sum(int(ch) for ch in shy[:-1]) < len(shy) - 1:
        print 'BUG'
        import pdb;pdb.set_trace()

    return extra

def main(inFile):
    with open(inFile) as inp, open(inFile.replace('.in', '.out'), 'w') as out:
        T = int(inp.readline().strip())
        for t in xrange(T):
            N, shy = inp.readline().strip().split()
            out.write('Case #%d: %s\n' % (t + 1, solve(shy)))

if __name__ == '__main__':
    if len(sys.argv) < 2:
        sys.exit('Usage: %s input.in' % sys.argv[0])
    main(sys.argv[1])
