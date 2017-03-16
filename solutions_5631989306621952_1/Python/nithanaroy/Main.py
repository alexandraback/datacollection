if __name__ == '__main__':
    t = int(raw_input())
    i = 1
    while t > 0:
        s = raw_input()
        r = [s[0]]
        for c in s[1:]:
            if c >= r[0]:
                r.insert(0, c)
            else:
                r.append(c)
        print 'Case #%d: %s' % (i, ''.join(r))
        t -= 1
        i += 1
