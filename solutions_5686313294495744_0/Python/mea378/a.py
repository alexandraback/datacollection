if __name__ == '__main__':
    input = 'C-small-attempt0.in' # A-large.in
    output = 'C-small-attempt0.out' # A-large.out

    with open(input) as f:
        content = f.readlines()
    content = [x.strip('\n') for x in content]

    with open(output, 'w') as o:
        j = 1
        for i in xrange(int(content[0])):
            first = {}
            second = {}
            poss = set()
            j_start = j + 1
            j_end = j_start + int(content[j_start-1])
            for k in xrange(j_start, j_end):
                f, s = str.split(content[k])
                if f in first:
                    first[f] += 1
                else:
                    first[f] = 1
                if s in second:
                    second[s] += 1
                else:
                    second[s] = 1

            for k in xrange(j_start, j_end):
                f, s = str.split(content[k])
                if first[f] > 1 and second[s] > 1:
                    poss.add(f+' '+s)

            j = j_end

            o.write('Case #%d: %d' % ((i+1), len(poss)))
            o.write('\n')
