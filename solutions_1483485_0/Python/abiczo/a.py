if __name__ == '__main__':
    D = {
        'a': 'y', 'b': 'h', 'c': 'e', 'd': 's', 'e': 'o', 'f': 'c', 'g': 'v',
        'h': 'x', 'i': 'd', 'j': 'u', 'k': 'i', 'l': 'g', 'm': 'l', 'n': 'b',
        'o': 'k', 'p': 'r', 'q': 'z', 'r': 't', 's': 'n', 't': 'w', 'u': 'j',
        'v': 'p', 'w': 'f', 'x': 'm', 'y': 'a', 'z': 'q', ' ': ' '
    }

    for caseno in xrange(int(raw_input())):
        translated = raw_input()
        orig = ''.join(D[ch] for ch in translated)

        print 'Case #%d: %s' % (caseno + 1, orig)
