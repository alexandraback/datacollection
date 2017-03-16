
import sys

abc = 'abcdefghijklmnopqrstuvwxyz'
e2g = {'a': 'y', 'o': 'e', 'z': 'q'}

def learn_mapping(googlerese, english):
    for g, e in zip(googlerese, english):
        if e in abc:
            e2g[e] = g

learn_mapping('ejp mysljylc kd kxveddknmc re jsicpdrysi rbcpc ypc rtcsra dkh wyfrepkym veddknkmkrkcd de kr kd eoya kw aej tysr re ujdr lkgc jv',
              'our language is impossible to understand there are twenty six factorial possibilities so it is okay if you want to just give up')

e = set(abc) - set(e2g.keys())
g = set(abc) - set(e2g.values())
for gg, ee in zip(g, e):
    e2g[ee] = gg

g2e = dict([(v, k) for k, v in e2g.iteritems()])

def decode_googlerese(src):
    result = []
    for i in src:
        if i in g2e:
            result.append(g2e[i])
        else:
            result.append(i)
    return ''.join(result)

if __name__ == '__main__':
    with open(sys.argv[1]) as f:
        for index, case in enumerate(f.read().split('\n')[1:]):
            case = case.rstrip()
            if case:
                print 'Case #{0}: {1}'.format(index + 1, decode_googlerese(case))

