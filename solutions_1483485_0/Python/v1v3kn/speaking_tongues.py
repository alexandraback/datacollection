"""
Speaking tongues problem (Caesar Cipher)
"""

mapping = {'a': 'y', 'o': 'e', 'z': 'q', 'q': 'z'}

pairs = [
    ('our language is impossible to understand', 'ejp mysljylc kd kxveddknmc re jsicpdrysi'),
    ('there are twenty six factorial possibilities', 'rbcpc ypc rtcsra dkh wyfrepkym veddknkmkrkcd'),
    ('so it is okay if you want to just give up', 'de kr kd eoya kw aej tysr re ujdr lkgc jv')
]

for (text, crypt) in pairs:
    mapping.update(dict(zip(crypt, text)))

def transform(word):
    return ''.join(mapping[ch] for ch in  word)

def main():
    import sys
    f = open(sys.argv[1])
    out = open(sys.argv[2], 'w')
    index = 1
    lines = []
    f.next()
    while True:
        try:
            text = ' '.join(map(transform, f.next().split()))
            lines.append("Case #%d: %s" % (index, text))
            index += 1
        except StopIteration:
            break
    out.write('\n'.join(lines))
    out.close()

if __name__ == '__main__':
    main()