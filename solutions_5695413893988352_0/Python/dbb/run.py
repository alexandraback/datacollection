import sys

sys.stdin.readline()
casen = 0
while 1:
    ln = sys.stdin.readline()
    if not ln:
        break
    casen += 1
    ln = ln.strip()
    c_raw, j_raw = ln.split()
    c_prev = 0
    j_prev = 0
    c_out = ''
    j_out = ''
    for i in range(len(c_raw)):
        c = c_raw[i]
        j = j_raw[i]
        if c == '?' and j == '?':
            if c_prev == j_prev:
                c_out += '0'
                j_out += '0'
            elif c_prev < j_prev:
                c_out += '9'
                j_out += '0'
            else:
                c_out += '0'
                j_out += '9'
        if c != '?':
            c_out += c
            if j == '?':
                if c_prev == j_prev:
                    j_out += c
                elif c_prev < j_prev:
                    j_out += '0'
                else:
                    j_out += '9'
        if j != '?':
            j_out += j
            if c == '?':
                if c == '?' and c_prev == j_prev:
                    c_out += j
                elif c_prev < j_prev:
                    c_out += '9'
                else:
                    c_out += '0'
        c_prev = int(c_out)
        j_prev = int(j_out)
    print 'Case #%d: %s %s' % (casen, c_out, j_out)
