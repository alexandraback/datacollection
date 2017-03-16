def solve(l):
    c_str, j_str = str.split(l)
    c_new = []
    j_new = []
    larger = None
    smaller = None

    for i in xrange(len(c_str)):
        c = c_str[i]
        j = j_str[i]

        if c != '?' and j != '?':
            c_new.append(c)
            j_new.append(j)
            if int(c) > int(j):
                larger = c_new
                smaller = j_new
            elif int(j) > int(c):
                larger = j_new
                smaller = c_new
        elif c == '?' and j == '?':
            if larger is None:
                c_new.append('0')
                j_new.append('0')
            else:
                larger.append('0')
                smaller.append('9')
                larger = None
                smaller = None
        elif c == '?' and j != '?':
            if larger is None:
                c_new.append(j)
                j_new.append(j)
            else:
                larger.append('0')
                smaller.append('9')
                larger = None
                smaller = None
        elif c != '?' and j == '?':
            if larger is None:
                c_new.append(c)
                j_new.append(c)
            else:
                larger.append('0')
                smaller.append('9')
                larger = None
                smaller = None

    return ''.join(c_new) + ' ' + ''.join(j_new)

if __name__ == '__main__':
    input = 'B-small-attempt0.in' # A-large.in
    output = 'B-small-attempt0.out' # A-large.out

    with open(input) as f:
        content = f.readlines()
    content = [x.strip('\n') for x in content]

    with open(output, 'w') as o:
        for i, l in enumerate(content[1:]):
            o.write('Case #%d: %s' % ((i+1), solve(l)))
            o.write('\n')
