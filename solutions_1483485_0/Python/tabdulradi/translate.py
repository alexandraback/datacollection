def populate_map(g_e_map, googlerese, english):
    for g, e in zip(googlerese, english):
        g_e_map[g] = e

g_e_map = {}
populate_map(g_e_map, 'z', 'q')
populate_map(g_e_map, 'y qee', 'a zoo')
populate_map(g_e_map, 'ejp mysljylc kd kxveddknmc re jsicpdrysi', 'our language is impossible to understand')
populate_map(g_e_map, 'rbcpc ypc rtcsra dkh wyfrepkym veddknkmkrkcd', 'there are twenty six factorial possibilities')
populate_map(g_e_map, 'de kr kd eoya kw aej tysr re ujdr lkgc jv', 'so it is okay if you want to just give up')

def trans(googlerese):
    return ''.join([g_e_map[g] for g in googlerese])


def file_handler(f):
    f.readline()
    for i, line in enumerate(f):
        yield "Case #%s: %s" % (i+1, trans(line.strip())) # Strip new line character

import sys
for line in file_handler(sys.stdin):
    print line
